#include "stdafx.h"
#include "HeapSort.h"
#include <iostream>
#include <fstream>
#include <algorithm>


CHeapSort::CHeapSort()
{
}


CHeapSort::CHeapSort(int N)
{
	m_nNumberOfElements = N;
	m_pElement = new int[N + 1];
	m_nindex = 0;

}

CHeapSort::~CHeapSort()
{
	//delete[] m_pElement;
}


void CHeapSort::FileToSort(std::string filepath)
{
	m_sFileToSort = filepath;
}

void CHeapSort::swim(int k)
{
	while (k > 1 && m_pElement[k / 2] < m_pElement[k])
	{
		std::swap(m_pElement[k], m_pElement[(k / 2)]);
		k = k / 2;
	}
}

void CHeapSort::insert(int value)
{
	m_pElement[++m_nindex] = value;
	swim(m_nindex);
}

void CHeapSort::sink(int k)
{
	
	while (2 * k <= m_nindex)
	{
		int j = 2 * k;
		if (j < m_nindex && m_pElement[j] < m_pElement[j + 1])
			j++;
		if (m_pElement[k]>m_pElement[j])break;
		std::swap(m_pElement[k], m_pElement[j]);
		k = j;

	}
}

void CHeapSort::deleteMAX()
{
	std::swap(m_pElement[1], m_pElement[m_nindex--]);
	sink(1);
}

void CHeapSort::Sort()
{
	std::cout << "Enter CHeapSort::Sort() \n";
	for (int i = 1; i < m_nNumberOfElements; ++i)
		deleteMAX();
	std::cout << "Enter CHeapSort::Sort() \n";
}

void CHeapSort::Parse()
{
	std::cout << "Enter CHeapSort::Parse() \n";
	std::ifstream input_file;
	input_file.open(m_sFileToSort);
	int i = 0;
	while (!input_file.eof())
	{
		std::string s;
		std::getline(input_file, s);
		
		int x = atoi(s.c_str());
		insert(x);
	}
	input_file.close();
	std::cout << "Leave CHeapSort::Parse() \n";
}

void CHeapSort::WriteSortedListToFile(std::string filepath)
{
	std::cout << "Enter CHeapSort::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 1; i < m_nNumberOfElements+1; ++i)
	{
		sorted << m_pElement[i] << std::endl;
	}
	std::cout << "Leave CHeapSort::WriteSortedListToFile \n";
}