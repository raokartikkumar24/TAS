// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataSet.h"
#include <string>
#include <iostream>
#include "SortManager.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CDataSet dataset;
	CSortManager manager;
	std::string input = dataset.ReadFile();
	//manager.BubbleSort(input);
	//manager.InsertionSort(input);
	manager.SelectionSort(input);
	manager.printTimings();

	return 0;
}

