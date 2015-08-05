#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

class CHeapSort
{
private:
	std::string m_sFileToSort;
	int* m_pElement;
	int m_nindex;
	int m_nNumberOfElements;
public:

	CHeapSort();
	CHeapSort(int n);
	~CHeapSort();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);
	void swim(int k);
	void insert(int value);
	void sink(int k);
	void deleteMAX();

};


