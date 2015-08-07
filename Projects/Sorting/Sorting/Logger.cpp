#include "stdafx.h"
#include "Logger.h"


CLogger::CLogger()
{
	//m_fLogFile.open("Log.txt");
}


CLogger::~CLogger()
{
	//m_fLogFile.close();
}

void CLogger::Log(int linenumber, std::string filename, std::string message)
{
	if (m_fLogFile.is_open()) {
		m_fLogFile << std::left << std::setw(2) << linenumber << "\t"
			<< std::setw(10) << filename << "\t"
			<< std::setw(25) << message << "\n";
	}

}

std::ofstream CLogger::m_fLogFile("LogFile.log");