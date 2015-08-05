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
	std::cout << "Enter CBubbleSort::Sort() \n";

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

	std::cout << "Leave CBubbleSort::Sort() \n";

}

void CBubbleSort::Parse()
{
	std::cout << "Enter CBubbleSort::Parse() \n";
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
	std::cout << "Leave CBubbleSort::Parse() \n";
}

void CBubbleSort::WriteSortedListToFile(std::string filepath)
{
	std::cout << "Enter CBubbleSort::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	std::cout << "Leave CBubbleSort::WriteSortedListToFile \n";
}
