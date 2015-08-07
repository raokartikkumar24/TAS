#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
class CLogger
{
public:
	CLogger();
	~CLogger();

	static void Log(int linenumber, std::string filename, std::string message);

private:
	static std::ofstream m_fLogFile;

};

