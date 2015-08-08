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
	std::ifstream t;
	t.open("C:\\temp\\time_small.txt");
	std::ifstream tl;
	tl.open("C:\\temp\\time_large.txt");
	std::ofstream outputfile("C:\\temp\\sort_time.html");
	std::string htmldoc = "";
	outputfile << "<!DOCTYPE html>" << std::endl;
	outputfile << "<body>" << std::endl;
	outputfile << "<p> Timings for Small data set </p>";
	outputfile << "<table border = '1'>" << std::endl;
	while (!t.eof())
	{
		std::string line;
		std::getline(t, line);
		outputfile << "<tr> <td>";
		outputfile << line << std::endl;
		outputfile << "</td> </tr>";

	}
	t.close();
	outputfile << "</table>" << std::endl;
	outputfile << "<p> Timings for Large data set </p>";
	outputfile << "<table border = '1'>" << std::endl;

	while (!tl.eof())
	{
		std::string line;
		std::getline(tl, line);
		outputfile << "<tr> <td>";
		outputfile << line << std::endl;
		outputfile << "</td> </tr>";

	}


	outputfile << "</table>" << std::endl;
	outputfile << "</body>" << std::endl;
	outputfile << "</html>" << std::endl;

	outputfile.close();
	t.close();
	tl.close();

}