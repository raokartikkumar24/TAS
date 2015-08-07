// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataSet.h"
#include <string>
#include <iostream>
#include "SortManager.h"
#include "WebServer.h"
#include "HTMLFormat.h"

int _tmain(int argc, _TCHAR* argv[])
{

	std::cout << "Generating Data sets \n";
	std::string loc1 = "C:\\temp\\smalldataset.txt";
	std::string loc2 = "C:\\temp\\largedataset.txt";
	CDataSet dataset(loc1, loc2);

	std::cout << "Completed generating Data sets \n";
	CSortManager manager(false);
	std::string inputsmall = dataset.ReadFileSmall();
	
	std::cout << "Sorting started for small data set \n";
	manager.HeapSort(inputsmall,false);
	manager.QuickSort(inputsmall);
	manager.MergeSort(inputsmall);
	manager.BubbleSort(inputsmall);
	manager.InsertionSort(inputsmall);
	manager.SelectionSort(inputsmall);
	std::cout << "Sorting completed for small data set \n";


	std::cout << std::endl;
	std::string inputlarge = dataset.ReadFileLarge();
	CSortManager largemanager(true);
	std::cout << "Sorting completed for large data set \n";
	largemanager.HeapSort(inputlarge, true);
	largemanager.QuickSort(inputlarge);
	largemanager.MergeSort(inputlarge);
	largemanager.BubbleSort(inputlarge);
	largemanager.InsertionSort(inputlarge);
	largemanager.SelectionSort(inputlarge);

	std::cout << "Sorting completed for large data set \n";
	std::cout << "\n";


	CHTMLFormat format;
	format.display();

	CWebServer server;
	server.start();

	return 0;
}

