#include "stdafx.h"
#include "QuickSort.h"
#include "DataSet.h"
#include <fstream>
#include <iostream>
#include <algorithm>


CQuickSort::CQuickSort()
{
}


CQuickSort::~CQuickSort()
{
}

void CQuickSort::FileToSort(std::string filepath)
{
	m_sFileToSort = filepath;
}



int CQuickSort::Partition(int l, int r)
{
	int i = l - 1;
	int j = r;
	while (true)
	{
		while (listofnumbers[++i]<listofnumbers[r]) if (i == r) break; 
		while (listofnumbers[r]<listofnumbers[--j]) if (j == l) break; 

		if (i >= j) break; 

		std::swap(listofnumbers[i], listofnumbers[j]);

	}

	std::swap(listofnumbers[i], listofnumbers[r]);
	return i;
}

void CQuickSort::Sort()
{
	std::cout << "Enter CQuickSort::Sort() \n";

	Sort(0, listofnumbers.size() - 1);
	
	std::cout << "Leave CQuickSort::Sort() \n";

}

void CQuickSort::Sort(int l, int r)
{
	if (r > l)
	{
		int pivot = Partition(l, r);
		Sort(l, pivot - 1);
		Sort(pivot + 1, r);
	}
}

void CQuickSort::Parse()
{
	std::cout << "Enter CQuickSort::Parse() \n";
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
	std::cout << "Leave CQuickSort::Parse() \n";
}

void CQuickSort::WriteSortedListToFile(std::string filepath)
{
	std::cout << "Enter CQuickSort::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	std::cout << "Leave CQuickSort::WriteSortedListToFile \n";
}

