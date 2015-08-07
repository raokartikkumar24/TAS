#include "stdafx.h"
#include "HeapSort.h"
#include <iostream>
#include <fstream>
#include <algorithm>


CHeapSort::CHeapSort()
{
}


CHeapSort::CHeapSort(__int64 N)
{
	m_nNumberOfElements = N+1;
	m_pElement = new __int64[N + 2];
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

void CHeapSort::swim(__int64 k)
{
	while (k > 1 && m_pElement[k / 2] < m_pElement[k])
	{
		std::swap(m_pElement[k], m_pElement[(k / 2)]);
		k = k / 2;
	}
}

void CHeapSort::insert(__int64 value)
{
	m_pElement[++m_nindex] = value;
	swim(m_nindex);
}

void CHeapSort::sink(__int64 k)
{
	while (2 * k <= m_nindex)
	{
		__int64 j = 2 * k;
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
	CLogger::Log(__LINE__, __FILE__, "Enter Sort()  ");
	for (__int64 i = 1; i < m_nNumberOfElements; ++i)
		deleteMAX();
	CLogger::Log(__LINE__, __FILE__, "Leave Sort() ");
}

void CHeapSort::Parse()
{
	CLogger::Log(__LINE__, __FILE__, "Enter Parse() ");
	std::ifstream input_file;
	input_file.open(m_sFileToSort);
	while (!input_file.eof())
	{
		std::string s;
		std::getline(input_file, s);
		
		int x = atoi(s.c_str());
		insert(x);
	}
	input_file.close();
	CLogger::Log(__LINE__, __FILE__, "Leave Parse() ");
}

void CHeapSort::WriteSortedListToFile(std::string filepath)
{
	CLogger::Log(__LINE__, __FILE__, "Enter WriteSortedListToFile() ");
	std::ofstream sorted(filepath);

	for (__int64 i = 1; i < m_nNumberOfElements+1; ++i)
	{
		sorted << m_pElement[i] << std::endl;
	}
	CLogger::Log(__LINE__, __FILE__, "Leave WriteSortedListToFile() ");
}