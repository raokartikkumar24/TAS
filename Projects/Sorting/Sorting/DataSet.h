#pragma once
#include <fstream>
#include <string>
class CDataSet
{
private:
	///*
	//Data set file with randomized data
	//*/
	std::ofstream m_fLargeDataset;
	std::ofstream m_fSmallDataset;

	///*
	//Write the sorted data to files
	//*/
	std::ofstream m_fsortedLargeDataset;
	std::ofstream m_fsortedSmallDataset;

	std::string m_sInputLocation;
	std::string m_sOutputLocation;

public:
	CDataSet();
	~CDataSet();
	CDataSet(std::string);
	void createRandomDatasetLarge();
	void createRandomDatasetSmall();

	std::string ReadFile();
	std::string ReadOutputFile();
	void WriteSortedFile();
};

