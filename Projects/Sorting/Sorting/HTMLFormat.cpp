#include "stdafx.h"
#include "HTMLFormat.h"


CHTMLFormat::CHTMLFormat()
{
}


CHTMLFormat::~CHTMLFormat()
{
}


void CHTMLFormat::display()
{
	std::ifstream t("C:\\temp\\time_small.txt");
	std::ofstream outputfile("c:\\temp\\sort_time.html");
	std::string htmldoc = "";
	outputfile << "<!DOCTYPE html>" << std::endl;
	outputfile << "<body>" << std::endl;
	outputfile << "<table border = '1'>" << std::endl;
	while (!t.eof())
	{
		std::string line;
		std::getline(t, line);
		outputfile << "<tr> <td>";
		outputfile << line << std::endl;
		outputfile << "</td> </tr>";

	}

	outputfile << "</table>" << std::endl;
	outputfile << "</body>" << std::endl;
	outputfile << "</html>" << std::endl;

	outputfile.close();
	t.close();

}