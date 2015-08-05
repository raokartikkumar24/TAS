#include "stdafx.h"
#include "DataSet.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <limits>

#define MAX std::numeric_limits<int>::max();
CDataSet::CDataSet()
{
	m_sInputLocation = "C:\\karthik\\randomdataset.txt";
	m_sOutputLocation = "C:\\karthik\\sortedDataset.txt";
	//createRandomDatasetLarge();
	createRandomDatasetSmall();

}

CDataSet::CDataSet(std::string location)
{
	m_sInputLocation = location;
}


CDataSet::~CDataSet()
{
}


void CDataSet::createRandomDatasetLarge()
{
	m_fLargeDataset.open(m_sInputLocation);
	long long int i = 0;
	for (; i < INT_MAX; ++i)
		m_fLargeDataset << (i + rand()) % INT_MAX << std::endl;

}

void CDataSet::createRandomDatasetSmall()
{
	std::cout << "Enter CDataSet::createRandomDatasetSmall \n";
	m_fSmallDataset.open(m_sInputLocation);
	int i = 0;
	for (; i < 10000; ++i)
		m_fSmallDataset << ( rand()) % (10000) << std::endl;
	std::cout << "Leave CDataSet::createRandomDatasetSmall \n";
}

std::string CDataSet::ReadFile()
{
	return m_sInputLocation;
}

std::string CDataSet::ReadOutputFile()
{
	return m_sOutputLocation;
}