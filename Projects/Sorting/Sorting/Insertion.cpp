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
	CLogger::Log(__LINE__, __FILE__, "Enter Sort()");
	if (listofnumbers.size() > 0)
	{
		int num = listofnumbers.size();
		int insertedElement, i, j;
		for (i = 1; i < num; i++)
		{
			insertedElement = listofnumbers[i];
			j = i-1;
			if (j == num) break;
			while ((j >= 0) && (listofnumbers[j] > insertedElement))
			{
				//keep on moving the element until we find the correct position for that element.
				listofnumbers[j+1] = listofnumbers[j]; 
				j = j - 1;
			}
			listofnumbers[j+1] = insertedElement;

		}
	}
	else
	{
		CLogger::Log(__LINE__, __FILE__, "Error . The List is empty");
	}
	CLogger::Log(__LINE__, __FILE__, "Leave Sort()");

}

void CInsertion::Parse()
{
	CLogger::Log(__LINE__, __FILE__, "Enter Parse()");
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
	CLogger::Log(__LINE__, __FILE__, "Leave Parse()");
}

void CInsertion::WriteSortedListToFile(std::string filepath)
{
	CLogger::Log(__LINE__, __FILE__, "Enter WriteSortedListToFile()");
	std::ofstream sorted(filepath);

	for (int i = 0; i < (int)listofnumbers.size(); ++i)
	{
		sorted << listofnumbers[i] << std::endl;
	}
	CLogger::Log(__LINE__, __FILE__, "Leave WriteSortedListToFile()");
}
