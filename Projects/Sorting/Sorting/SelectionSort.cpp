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
	std::cout << "Enter CSelectionSort::Sort() \n";

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
		std::cout << "Error : List is empty \n";
	}
	std::cout << "Leave CSelectionSort::Sort() \n";

}

void CSelectionSort::Parse()
{
	std::cout << "Enter CSelectionSort::Parse() \n";
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
	std::cout << "Leave CSelectionSort::Parse() \n";
}

void CSelectionSort::WriteSortedListToFile(std::string filepath)
{
	std::cout << "Enter CSelectionSort::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	std::cout << "Leave CSelectionSort::WriteSortedListToFile \n";
}
