#include "stdafx.h"
#include "MergeSort.h"
#include "DataSet.h"
#include <fstream>
#include <iostream>
#include <algorithm>


CMergeSort::CMergeSort()
{
}


CMergeSort::~CMergeSort()
{
}

void CMergeSort::FileToSort(std::string filepath)
{
	m_sFileToSort = filepath;
}



void CMergeSort::Merge(std::vector<int> &mainarray, std::vector<int> &aux, int lo, int mid, int hi)
{
	for (int k = lo; k <= hi; k++)
		aux[k] = mainarray[k];

	int i = lo, j = mid + 1;
	int len = mainarray.size();

	

	for (int p = lo; p <= hi; p++)
	{
		if (i > mid) mainarray[p] = aux[j++];
		else if (j > hi) mainarray[p] = aux[i++];
		else if (aux[j] < aux[i]) mainarray[p] = aux[j++];
		else mainarray[p] = aux[i++];
	}
}


void CMergeSort::Sort()
{
	std::cout << "Enter CMergeSort::Sort() \n";

	std::vector<int> auxilary(listofnumbers.size());
	std::vector<int> another(listofnumbers.size());
	another = listofnumbers;
	Sort(another,auxilary,0, listofnumbers.size() - 1);

	listofnumbers = another;


	std::cout << "Leave CMergeSort::Sort() \n";

}

void CMergeSort::Sort(std::vector<int> &mainarray, std::vector<int> &aux, int lo, int high)
{
	if ( lo < high )
	{
		int mid = (lo + high) / 2;
		Sort(mainarray,aux,lo,mid);
		Sort(mainarray,aux,mid+1,high);
		Merge(mainarray,aux, lo, mid, high);

	}
}

void CMergeSort::Parse()
{
	std::cout << "Enter CMergeSort::Parse() \n";
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
	std::cout << "Leave CMergeSort::Parse() \n";
}

void CMergeSort::WriteSortedListToFile(std::string filepath)
{


	std::cout << "Enter CMergeSort::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	std::cout << "Leave CMergeSort::WriteSortedListToFile \n";
}

