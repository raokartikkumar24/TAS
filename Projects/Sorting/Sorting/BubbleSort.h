#pragma once
#include <vector>
class CBubbleSort
{
private:
	std::string m_sFileToSort;
	std::vector<int> listofnumbers;
public:
	CBubbleSort();
	~CBubbleSort();

	void Sort();
	void FileToSort(std::string filepath);
	void Parse();
	void WriteSortedListToFile(std::string filepath);
	
};

