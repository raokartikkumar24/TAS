#pragma once
#include <vector>
#include <string>
#include "Logger.h"
class CSelectionSort
{
private:
	std::string m_sFileToSort;
	std::vector<int> listofnumbers;
public:

	CSelectionSort();
	~CSelectionSort();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);

};


