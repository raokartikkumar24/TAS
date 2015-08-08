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
	
	std::cout << "Web Server \n";
	std::cout << "Datasets are generated and given as input for sorting \n";
	std::cout << "Small data sets are of 10^5 range \n";
	std::cout << "Large data sets are of INT_MAX range which is more than 10^10.. \n";
	std::cout << "All sorting techniques use small data set to sort and store the resutl in a .html file \n";
	std::cout << "Only heap sort, quick sort and merge sort are used to sort the large data set \n";

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

	std::string inputlarge = dataset.ReadFileLarge();
	CSortManager largemanager(true);
	std::cout << "Sorting started for large data set \n";
	largemanager.HeapSort(inputlarge, true);
	largemanager.QuickSort(inputlarge);
	largemanager.MergeSort(inputlarge);
	//largemanager.BubbleSort(inputlarge);
	//largemanager.InsertionSort(inputlarge);
	//largemanager.SelectionSort(inputlarge);

	std::cout << "Sorting completed for large data set \n";
	std::cout << "\n";

	CWebServer server;
	server.start();


	CHTMLFormat format;
	format.display();

	std::cout << "Results are stored at C:\\temp\\sort_time.html \n";
	

	return 0;
}

