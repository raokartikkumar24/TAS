#include "stdafx.h"
#include "SortManager.h"


CSortManager::CSortManager()
{
}


CSortManager::~CSortManager()
{
}

void CSortManager::BubbleSort(std::string inputfilepath)
{

		CBubbleSort bubblesort;
		bubblesort.FileToSort(inputfilepath);
		bubblesort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		bubblesort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "C:\\karthik\\sortedlist_bubblesort.txt";
		bubblesort.WriteSortedListToFile(outfilepath);

		std::pair<std::string, double> p;
		p.first = "Bubble Sort";
		p.second = duration;
		m_sortingTime.push_back(p);


}

void CSortManager::InsertionSort(std::string inputfilepath)
	{

		CInsertion insertionsort;
		insertionsort.FileToSort(inputfilepath);
		insertionsort.Parse();

		std::clock_t start;
		double duration;

		start = std::clock();

		insertionsort.Sort();

		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		std::string outfilepath = "C:\\karthik\\sortedlist_insertionsort.txt";
		insertionsort.WriteSortedListToFile(outfilepath);

		std::pair<std::string, double> p;
		p.first = "Insertion Sort";
		p.second = duration;
		m_sortingTime.push_back(p);
}


void CSortManager::SelectionSort(std::string inputfilepath)
{

	CSelectionSort selectionsort;
	selectionsort.FileToSort(inputfilepath);
	selectionsort.Parse();

	std::clock_t start;
	double duration;

	start = std::clock();

	selectionsort.Sort();

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	std::string outfilepath = "C:\\karthik\\sortedlist_selectionsort.txt";
	selectionsort.WriteSortedListToFile(outfilepath);

	std::pair<std::string, double> p;
	p.first = "Selection Sort";
	p.second = duration;
	m_sortingTime.push_back(p);
}

void CSortManager::printTimings()
	{
		std::cout << "Algorithm" << "\t" << "Time" << "\n";
		std::cout << "----------------------------------- \n";
		for (auto x : m_sortingTime)
		{
			std::cout << x.first << "\t" << x.second << "\n";
		}
	}


