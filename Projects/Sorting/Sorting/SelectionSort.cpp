#include "stdafx.h"
#include "SelectionSort.h"
#include "DataSet.h"
#include <fstream>
#include <iostream>
#include <algorithm>


CSelectionSort::CSelectionSort()
{
}


CSelectionSort::~CSelectionSort()
{
}

void CSelectionSort::FileToSort(std::string filepath)
{
	m_sFileToSort = filepath;
}

void CSelectionSort::Sort()
{
	CLogger::Log(__LINE__, __FILE__, "Enter Sort()");

	if (listofnumbers.size() > 0)
	{
		int num = listofnumbers.size();
		int i, j, first;
		for (i = 0; i < num-1; ++i)
		{
			first = 0;
			for (j = i+1; j < num ; j++)
			{
				if (listofnumbers[j] < listofnumbers[first])
					first = j;
			}
			std::swap(listofnumbers[first], listofnumbers[i]);
		}
	}
	else
	{
		CLogger::Log(__LINE__, __FILE__, "Error. List is empty");
	}
	CLogger::Log(__LINE__, __FILE__, "Leave Sort()");

}

void CSelectionSort::Parse()
{
	CLogger::Log(__LINE__, __FILE__, "Enter Parse()");
	std::ifstream input_file;
	input_file.open(m_sFileToSort);

	while (!input_file.eof())
	{
		std::string s;
		std::getline(input_file, s);
		int x = atoi(s.c_str());
		listofnumbers.push_back(x);

	}
	input_file.close();
	CLogger::Log(__LINE__, __FILE__, "Leave Parse()");
}

void CSelectionSort::WriteSortedListToFile(std::string filepath)
{
	CLogger::Log(__LINE__, __FILE__, "Enter WriteSortedListToFile()");
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	CLogger::Log(__LINE__, __FILE__, "Leave WriteSortedListToFile()");
}
