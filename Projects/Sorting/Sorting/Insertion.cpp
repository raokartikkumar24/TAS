#include "stdafx.h"
#include "Insertion.h"
#include "DataSet.h"
#include <fstream>
#include <iostream>
#include <algorithm>


CInsertion::CInsertion()
{
}


CInsertion::~CInsertion()
{
}

void CInsertion::FileToSort(std::string filepath)
{
	m_sFileToSort = filepath;
}

void CInsertion::Sort()
{
	std::cout << "Enter CInsertion::Sort() \n";

	if (listofnumbers.size() > 0)
	{
		int num = listofnumbers.size();
		for (int i = 0; i < num; i++)
		{
			for (int j = i + 1; j > 0 && (j < num ); j--)
			{
				if (listofnumbers[j - 1] > listofnumbers[j])
				{
					std::swap(listofnumbers[j], listofnumbers[j - 1]);

				}
			}
			
		}
	}
	else
	{
		std::cout << "Error : List is empty \n";
	}
	std::cout << "Leave CInsertion::Sort() \n";

}

void CInsertion::Parse()
{
	std::cout << "Enter CInsertion::Parse() \n";
	std::ifstream input_file;
	input_file.open(m_sFileToSort);

	while (!input_file.eof())
	{
		std::string s;
		std::getline(input_file, s);
		int x = atoi(s.c_str());
		listofnumbers.push_back(x);

	}
	input_file.close();
	std::cout << "Leave CInsertion::Parse() \n";
}

void CInsertion::WriteSortedListToFile(std::string filepath)
{
	std::cout << "Enter CInsertion::WriteSortedListToFile \n";
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	std::cout << "Leave CInsertion::WriteSortedListToFile \n";
}
