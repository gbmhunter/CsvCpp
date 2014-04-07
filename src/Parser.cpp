//!
//! @file 			Parser.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/03
//! @brief
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/Parser.hpp"

namespace Csv
{

	void Parser::SetFilename(std::string filename)
	{
		this->filename = filename;
	}

	Row Parser::ReadRow()
	{
		std::ifstream myIfStream(this->filename, std::ifstream::in);

		if ( (myIfStream.rdstate() & std::ifstream::failbit ) != 0 )
			std::cerr << "Error opening 'test.csv'\n";

		std::string csvLine;

		// Read a line from the CSV file
		std::getline(myIfStream, csvLine);

		std::cout << "csvLine = " << csvLine << "\r\n";

		// Return a single row from the CSV file
		return this->ExtractElementsToRow(csvLine);

	}

	Table Parser::ReadEntireFile()
	{
		Table csvTable;

		std::ifstream myIfStream(this->filename, std::ifstream::in);

		if ( (myIfStream.rdstate() & std::ifstream::failbit ) != 0 )
		{
			std::cerr << "Error opening '" << this->filename << "'\n";
			throw "Couldn't open file.\r\n";
		}

		std::string csvLine;

		while(1)
		{
			// Read a line from the CSV file
			std::getline(myIfStream, csvLine);

			std::cout << "csvLine = " << csvLine << "\r\n";

			// Return a single row from the CSV file
			csvTable.Add(this->ExtractElementsToRow(csvLine));

			if(myIfStream.eof())
			{
				std::cerr << "End of file reached.\r\n";
				break;
			}

			if (csvLine.empty())
			{
				std::cerr << "csvLine empty.\r\n";
				break;
			}

		}

		return csvTable;
	}

	Row Parser::ExtractElementsToRow(std::string csvLine)
	{
		int lastPosOfFieldSeperator = 0;
		Row csvRow;
		while(1)
		{
			int nextPosOfFieldSeperator = csvLine.find(',', lastPosOfFieldSeperator + 1);

			int x = 0;
			std::string element;

			if(nextPosOfFieldSeperator == (int)std::string::npos)
			{
				for(x = lastPosOfFieldSeperator + 1; x < (int)csvLine.length(); x++)
				{
					element += csvLine[x];
				}
			}
			else
			{
				if(lastPosOfFieldSeperator == 0)
				{
					for(x = lastPosOfFieldSeperator; x < nextPosOfFieldSeperator; x++)
					{
						element += csvLine[x];
					}
				}
				else
				{
					for(x = lastPosOfFieldSeperator + 1; x < nextPosOfFieldSeperator; x++)
					{
						element += csvLine[x];
					}
				}
			}

			csvRow.Add(element);
			std::cout << "element = " << element << "\r\n";

			if(nextPosOfFieldSeperator == (int)std::string::npos)
			{
				std::cout << "End of line reached.\r\n";
				break;
			}

			lastPosOfFieldSeperator = nextPosOfFieldSeperator;
		}

		return csvRow;
	}

}

// EOF
