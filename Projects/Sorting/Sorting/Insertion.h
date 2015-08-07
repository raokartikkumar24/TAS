#pragma once
#include <vector>
#include "Logger.h"

class CInsertion
{
private:
	std::string m_sFileToSort;
	std::vector<int> listofnumbers;
public:
	
	CInsertion();
	~CInsertion();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);
public:

};

