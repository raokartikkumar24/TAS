// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataSet.h"
#include <string>
#include <iostream>
#include "SortManager.h"
#include "WebServer.h"

int _tmain(int argc, _TCHAR* argv[])
{

	CWebServer server;
	server.start();

	/*CDataSet dataset;
	CSortManager manager;
	std::string input = dataset.ReadFile();
	//manager.BubbleSort(input);
	//manager.InsertionSort(input);
	//manager.SelectionSort(input);
	manager.HeapSort(input);
	manager.QuickSort(input);
	manager.MergeSort(input);
	manager.printTimings();*/

	return 0;
}

