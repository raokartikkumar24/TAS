#pragma once
#include <string>
#include <vector>
#include "Logger.h"
class CMergeSort
{
private:
	std::string m_sFileToSort;
	std::vector<int> listofnumbers;
public:
	CMergeSort();
	~CMergeSort();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);

	void Merge(std::vector<int>&mainarray,std::vector<int> &aux, int l, int mid, int r);
	void Sort(std::vector<int>&mainarray, std::vector<int> &aux, int l, int r);
};

