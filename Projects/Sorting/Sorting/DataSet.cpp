#include "stdafx.h"
#include "DataSet.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <limits>

CDataSet::CDataSet()
{
	m_sInputLocation = "smallandomdataset.txt";
	m_sLargeDatasetLocation = "largerandomdataset.txt";
	createRandomDatasetLarge();
	createRandomDatasetSmall();

}

CDataSet::CDataSet(std::string smalldataset, std::string largedataset)
{
	m_sInputLocation = smalldataset;
	m_sLargeDatasetLocation = largedataset;
	createRandomDatasetSmall();
	createRandomDatasetLarge();
	
}


CDataSet::~CDataSet()
{
}


void CDataSet::createRandomDatasetLarge()
{
	CLogger::Log(__LINE__, __FILE__, "Enter createRandomDatasetLarge()");
	m_fLargeDataset.open(m_sLargeDatasetLocation);
	long long int i = 0;
	for (; i < (INT_MAX/4000); ++i)
		m_fLargeDataset << ( rand()) % (INT_MAX/4000) << std::endl;
	CLogger::Log(__LINE__, __FILE__, "Leave createRandomDatasetLarge()");
}

void CDataSet::createRandomDatasetSmall()
{
	CLogger::Log(__LINE__, __FILE__, "Enter createRandomDatasetSmall()");
	m_fSmallDataset.open(m_sInputLocation);
	int i = 0;
	for (; i < 10000; ++i)
		m_fSmallDataset << ( rand()) % (10000) << std::endl;
	CLogger::Log(__LINE__, __FILE__, "Leave createRandomDatasetSmall()");
}

std::string CDataSet::ReadFileSmall()
{
	CLogger::Log(__LINE__, __FILE__, "Small data set location");
	CLogger::Log(__LINE__, __FILE__, m_sInputLocation);
	return m_sInputLocation;
}

std::string CDataSet::ReadFileLarge()
{
	CLogger::Log(__LINE__, __FILE__, "Large data set File location");
	CLogger::Log(__LINE__, __FILE__, m_sLargeDatasetLocation);
	return m_sLargeDatasetLocation;
}

