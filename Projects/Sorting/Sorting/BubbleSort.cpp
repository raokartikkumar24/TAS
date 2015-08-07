#include "stdafx.h"
#include "BubbleSort.h"
#include "DataSet.h"
#include <fstream>
#include <iostream>


CBubbleSort::CBubbleSort()
{
}


CBubbleSort::~CBubbleSort()
{
}

void CBubbleSort::FileToSort(std::string filepath)
{
	m_sFileToSort = filepath;
}

void CBubbleSort::Sort()
{
	CLogger::Log(__LINE__, __FILE__, "Enter Sort()");
	if (listofnumbers.size() > 0)
	{
		int num = listofnumbers.size();
		int i, j;
		for (i = 0; i < num; i++) {
			for (j = 0; j < num - 1; j++) {
				if (listofnumbers[j] > listofnumbers[j + 1])
				{
					std::swap(listofnumbers[j], listofnumbers[j + 1]);
				}
			}
		}
	}

	CLogger::Log(__LINE__, __FILE__, "Leave Sort()");

}

void CBubbleSort::Parse()
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

void CBubbleSort::WriteSortedListToFile(std::string filepath)
{
	CLogger::Log(__LINE__, __FILE__, "Enter WriteSortedListToFile()");
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	CLogger::Log(__LINE__, __FILE__, "Leave WriteSortedListToFile()");
}
