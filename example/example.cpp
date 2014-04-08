//!
//! @file 			example.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 		2014/04/07
//! @last-modified 	2014/04/07
//! @brief 			Example CsvCpp program, designed to be run on Linux.
//! @details
//!				See README.rst in root dir for more info.

#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>

#include "../api/CsvCpp.hpp"


/*
class Printer
{
public:
	void PrintDebug(const char* msg)
	{
		std::cout << msg;
	}

	void PrintCmdLine(const char* msg)
	{
		std::cout << msg;
	}

	void PrintError(const char* msg)
	{
		std::cout << msg;
	}
};*/

int main()
{
	// Configure print outputs
	//Printer printer;


	while(1)
	{
		char inputMsg[30];

		std::cin.get(inputMsg, 30);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}
}
