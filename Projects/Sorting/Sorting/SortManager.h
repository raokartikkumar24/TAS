#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "BubbleSort.h"
#include "Insertion.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>

class CSortManager
{
public:
	CSortManager(bool datasetsize);
	~CSortManager();
	void BubbleSort(std::string inputfilepath);
	void InsertionSort(std::string inputfilepath);
	void SelectionSort(std::string inputfilepath);
	void HeapSort(std::string inputfilepath, bool large);
	void QuickSort(std::string inputfilepath);
	void MergeSort(std::string inputfilepath);
	

	void printTimingsSmall(std::string sorttype,double value);
	void printTimingsLarge(std::string sorttype, double value);

private:
	std::vector<std::pair<std::string, double> > m_sortingTime;
	bool largedataset;
	std::ofstream m_fSmallDataset;
	std::ofstream m_fLargeDataset;
};

