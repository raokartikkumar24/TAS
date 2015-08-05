#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "BubbleSort.h"
#include "Insertion.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include <cstdio>
#include <ctime>
class CSortManager
{
public:
	CSortManager();
	~CSortManager();
	void BubbleSort(std::string inputfilepath);
	void InsertionSort(std::string inputfilepath);
	void SelectionSort(std::string inputfilepath);
	void HeapSort(std::string inputfilepath);
	void printTimings();

private:
	std::vector<std::pair<std::string, double> > m_sortingTime;
};

