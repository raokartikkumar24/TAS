#pragma once
#include <vector>
#include <string>
#include "Logger.h"
class CQuickSort
{
private:
	std::string m_sFileToSort;
	std::vector<int> listofnumbers;
public:

	CQuickSort();
	~CQuickSort();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);

	int Partition(int l, int r);
	void Sort(int l, int r);

};
