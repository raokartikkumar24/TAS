#pragma once
#include <fstream>
#include <string>
#include "Logger.h"
class CDataSet
{
private:
	///*
	//Data set file with randomized data
	//*/
	std::ofstream m_fLargeDataset;
	std::ofstream m_fSmallDataset;

	std::string m_sInputLocation;
	std::string m_sLargeDatasetLocation;

public:
	CDataSet();
	~CDataSet();
	CDataSet(std::string smalldataset, std::string largedataset);
	void createRandomDatasetLarge();
	void createRandomDatasetSmall();

	std::string ReadFileSmall();
	std::string ReadFileLarge();
};

