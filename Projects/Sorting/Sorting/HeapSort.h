#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "Logger.h"
class CHeapSort
{
private:
	std::string m_sFileToSort;
	__int64* m_pElement;
	__int64 m_nindex;
	__int64 m_nNumberOfElements;
public:

	CHeapSort();
	CHeapSort(__int64 n);
	~CHeapSort();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);
	void swim(__int64 k);
	void insert(__int64 value);
	void sink(__int64 k);
	void deleteMAX();

};


