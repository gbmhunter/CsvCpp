//!
//! @file 			Parser.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/08
//! @brief
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/Parser.hpp"
#include "../include/Log.hpp"

namespace CsvCpp
{

	Parser::Parser()
	{
		// Default delimiter for CSV files
		this->lineDelimiter = "\r\n";

		// Default field delimiter for CSV files
		this->fieldDelimiter = ",";
	}

	void Parser::SetFilename(std::string filename)
	{
		this->filename = filename;
	}

	Record Parser::ReadRecord()
	{
		std::ifstream myIfStream(this->filename, std::ifstream::in);

		if ( (myIfStream.rdstate() & std::ifstream::failbit ) != 0 )
			errorMsg << "Error opening 'test.csv'\n";

		std::string csvLine;

		// Read a line from the CSV file
		std::getline(myIfStream, csvLine);

		std::istreambuf_iterator<char> eos;
		std::string theEntireFile(std::istreambuf_iterator<char>(myIfStream), eos);

		debugMsg << "The entire file:" << theEntireFile.c_str() << "\r\n";

		debugMsg << "csvLine = " << csvLine << "\r\n";

		// Return a single row from the CSV file
		return this->RecordStringToRecord(csvLine);

	}

	Table Parser::ReadEntireFile()
	{
		Table csvTable;

		std::ifstream myIfStream(this->filename, std::ifstream::in);

		if ( (myIfStream.rdstate() & std::ifstream::failbit ) != 0 )
		{
			errorMsg << "Error opening '" << this->filename << "'\n";
			throw "Couldn't open file.\r\n";
		}

		// Read the entire file stream into a string so we can peform
		// multi-character searches on it
		std::istreambuf_iterator<char> eos;
		std::string theEntireFile(std::istreambuf_iterator<char>(myIfStream), eos);

		debugMsg << "The entire file:" << theEntireFile << "\r\n";

		std::size_t found = theEntireFile.find("\r\n");

		while(1)
		{
			debugMsg << "Next iteration of processing loop.\r\n";
			std::string csvLine;
			// Read a line from the CSV file.

			// Search for the terminating character(s)
			std::size_t found = theEntireFile.find(this->lineDelimiter);

			if(found == std::string::npos)
			{
				// Terminating character not found, so read entire string
				// (must be last line)
				debugMsg << "Line delimiter not found, must be last line." << "\r\n";
				csvLine = theEntireFile.substr(0, theEntireFile.size());
				// Removes line from the stream
				theEntireFile.erase(0, theEntireFile.size());
			}
			else
			{
				debugMsg << "Line delimiter found at '" << found << "'." << "\r\n";
				csvLine = theEntireFile.substr(0, (unsigned long int)found);
				// Removes line from the stream (including the line delimiters)
				theEntireFile.erase(0, found + this->lineDelimiter.size());
			}

			debugMsg << "csvLine = " << csvLine << "\r\n";
			debugMsg << "csvLine size() = " << csvLine.size() << "\r\n";

			// This stops ExtractElementsToRow from running if the last valid
			// row has a new line character at the end
			if (csvLine.empty())
			{
				std::cerr << "csvLine empty.\r\n";
				break;
			}

			// Return a single row from the CSV file
			csvTable.Add(this->RecordStringToRecord(csvLine));

		}

		/*
		std::string csvLine;

		while(1)
		{
			// Read a line from the CSV file.
			// Removes line from the stream
			std::getline(myIfStream, csvLine);

			debugMsg << "csvLine = " << csvLine << "\r\n";
			debugMsg << "csvLine size() = " << csvLine.size() << "\r\n";

			// This stops ExtractElementsToRow from running if the last valid
			// row has a new line character at the end
			if (csvLine.empty())
			{
				std::cerr << "csvLine empty.\r\n";
				break;
			}

			// Return a single row from the CSV file
			csvTable.Add(this->ExtractElementsToRow(csvLine));

			if(myIfStream.eof())
			{
				debugMsg << "End of file reached.\r\n";
				break;
			}



		}*/

		return csvTable;
	}

	void Parser::CreateCsvFile(Table csvTable, std::string fileName)
	{
		// Create output stream to file
		std::ofstream outputFile(fileName);

		// Iterate through the CSV table
		uint32_t x, y;

		for(x = 0; x < csvTable.NumRecords(); x++)
		{
			for(y = 0; y < csvTable[x].NumElements(); y++)
			{
				//std::cout << "csvTable[" << x << "][" << y << "] = " << csvTable[x][y] << std::endl;
				//outputFile << csvTable[x][y] <<
			}
		}

		// Close the output file
		outputFile.close();
	}

	Record Parser::RecordStringToRecord(std::string csvLine)
	{
		int lastPosOfFieldDelimiter = 0;
		Record csvRecord;
		while(1)
		{
			// Find the next occurrence of the field delimiter
			int nextPosOfFieldDelimiter = csvLine.find(this->fieldDelimiter, lastPosOfFieldDelimiter + 1);

			int x = 0;
			std::string field;

			// Check to see if delimiter was found
			if(nextPosOfFieldDelimiter == (int)std::string::npos)
			{
				// Delimiter was not found
				for(x = lastPosOfFieldDelimiter + 1; x < (int)csvLine.length(); x++)
				{
					field += csvLine[x];
				}
			}
			else
			{
				// Next delimiter in row was found

				// Check to see wether we are at the first element or not
				if(lastPosOfFieldDelimiter == 0)
				{
					for(x = lastPosOfFieldDelimiter; x < nextPosOfFieldDelimiter; x++)
					{
						field += csvLine[x];
					}
				}
				else
				{
					for(x = lastPosOfFieldDelimiter + 1; x < nextPosOfFieldDelimiter; x++)
					{
						field += csvLine[x];
					}
				}
			}

			csvRecord.Add(field);
			debugMsg << "field = " << field << "\r\n";

			if(nextPosOfFieldDelimiter == (int)std::string::npos)
			{
				debugMsg << "End of record reached.\r\n";
				break;
			}

			lastPosOfFieldDelimiter = nextPosOfFieldDelimiter;
		}

		return csvRecord;
	}

}

// EOF
