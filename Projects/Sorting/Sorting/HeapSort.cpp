#include "stdafx.h"
#include "HeapSort.h"



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
	delete[] m_pElement;
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
	for (int i = 1; i < m_nNumberOfElements; ++i)
		deleteMAX();
}

void CHeapSort::Parse()
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

void CHeapSort::WriteSortedListToFile(std::string filepath)
{
	std::cout << "Enter CSelectionSort::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	std::cout << "Leave CSelectionSort::WriteSortedListToFile \n";
}