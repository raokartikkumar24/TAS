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
	CLogger::Log(__LINE__, __FILE__, "Enter Sort()");

	Sort(0, listofnumbers.size() - 1);
	
	CLogger::Log(__LINE__, __FILE__, "Leave Sort()");

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

void CQuickSort::WriteSortedListToFile(std::string filepath)
{
	CLogger::Log(__LINE__, __FILE__, "Enter WriteSortedListToFile()");
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	CLogger::Log(__LINE__, __FILE__, "Leave WriteSortedListToFile()");
}

