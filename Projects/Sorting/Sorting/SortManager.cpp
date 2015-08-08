#include "stdafx.h"
#include "SortManager.h"

CSortManager::CSortManager(bool datasetsize) : largedataset(datasetsize)
{
	if (datasetsize == false)
	{

		m_fSmallDataset.open("C:\\temp\\time_small.txt");
		m_fSmallDataset << "Algorithm" << "\t" << "Time" << "\n";
		m_fSmallDataset << "--------------------------- \n";
	}
	else
	{
		m_fLargeDataset.open("C:\\temp\\time_large.txt");
		m_fLargeDataset << "Algorithm" << "\t" << "Time" << "\n";
		m_fLargeDataset << "--------------------------- \n";
	}


}


CSortManager::~CSortManager()
{
	m_fSmallDataset.close();
	m_fLargeDataset.close();
}

void CSortManager::BubbleSort(std::string inputfilepath)
{

	try{

		CBubbleSort bubblesort;
		bubblesort.FileToSort(inputfilepath);
		bubblesort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		bubblesort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "sortedlist_bubblesort.txt";
		bubblesort.WriteSortedListToFile(outfilepath);

		std::string sorttype = "Bubble Sort";
		if (largedataset) printTimingsLarge(sorttype, duration);
		else printTimingsSmall(sorttype, duration);

	}
	catch (std::exception ex)
	{
		CLogger::Log(__LINE__, __FILE__, ex.what());
	}
		

}

void CSortManager::InsertionSort(std::string inputfilepath)
{
	try
	{
		CInsertion insertionsort;
		insertionsort.FileToSort(inputfilepath);
		insertionsort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		insertionsort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "sortedlist_insertionsort.txt";
		insertionsort.WriteSortedListToFile(outfilepath);

		std::string sorttype = "Insertion Sort";
		if (largedataset) printTimingsLarge(sorttype, duration);
		else printTimingsSmall(sorttype, duration);
	}
	catch (std::exception ex)
	{
		CLogger::Log(__LINE__, __FILE__, ex.what());
	}
		
}


void CSortManager::SelectionSort(std::string inputfilepath)
{
	try
	{
		CSelectionSort selectionsort;
		selectionsort.FileToSort(inputfilepath);
		selectionsort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		selectionsort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "sortedlist_selectionsort.txt";
		selectionsort.WriteSortedListToFile(outfilepath);

		std::string sorttype = "Selection Sort";
		if (largedataset) printTimingsLarge(sorttype, duration);
		else printTimingsSmall(sorttype, duration);
	}
	catch (std::exception ex)
	{
		CLogger::Log(__LINE__, __FILE__, ex.what());
	}

	
}

void CSortManager::HeapSort(std::string inputfilepath, bool large)
{
	long long int size = 0;
	if (large)
		size = ( INT_MAX / 4000 );
	else
		size = 10000;

	try
	{
		CHeapSort heapsort(size);
		heapsort.FileToSort(inputfilepath);
		heapsort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		heapsort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "sortedlist_heapsort.txt";
		heapsort.WriteSortedListToFile(outfilepath);

		std::string sorttype = "Heap Sort";
		if (largedataset) printTimingsLarge(sorttype, duration);
		else printTimingsSmall(sorttype, duration);
	}
	catch (std::exception ex)
	{
		CLogger::Log(__LINE__, __FILE__, ex.what());
	}
	
}

void CSortManager::QuickSort(std::string inputfilepath)
{
	try {

		CQuickSort quicksort;
		quicksort.FileToSort(inputfilepath);
		quicksort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		quicksort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "sortedlist_quicksort.txt";
		quicksort.WriteSortedListToFile(outfilepath);

		std::string sorttype = "Quick Sort";
		if (largedataset) printTimingsLarge(sorttype, duration);
		else printTimingsSmall(sorttype, duration);
	}
	catch (std::exception ex)
	{
		CLogger::Log(__LINE__, __FILE__, ex.what());
	}
	
}

void CSortManager::MergeSort(std::string inputfilepath)
{
	try
	{
		CMergeSort mergesort;
		mergesort.FileToSort(inputfilepath);
		mergesort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		mergesort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "sortedlist_mergesort.txt";
		mergesort.WriteSortedListToFile(outfilepath);

		std::string sorttype = "Merge Sort";
		if (largedataset) printTimingsLarge(sorttype, duration);
		else printTimingsSmall(sorttype, duration);

	}
	catch (std::exception ex)
	{
		CLogger::Log(__LINE__, __FILE__, ex.what());
	}
	

}


void CSortManager::printTimingsSmall(std::string sorttype, double value)
{
		
	if (m_fSmallDataset.is_open()) {
		//m_fSmallDataset << std::left << std::setw(8) << sorttype << "\t" << std::setw(6) << value << "\n";
		m_fSmallDataset << sorttype << " \t\t" << value << std::endl;
	}
	else
		std::cout << "cannot open file \n";
}

void CSortManager::printTimingsLarge(std::string sorttype,double value)
{
	if (m_fLargeDataset.is_open()){
		//m_fLargeDataset << std::left << std::setw(8) << sorttype << "\t" << std::setw(6) << value << "\n";
		m_fLargeDataset << sorttype << "\t\t" << value << std::endl;
	}
	else
		std::cout << "cannot open file \n";
}



