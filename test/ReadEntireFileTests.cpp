//!
//! @file 			ReadEntireFileTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/01
//! @last-modified 	2014/05/01
//! @brief 			Contains tests using the Parser::ReadEntireFile() function.
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(FilenameProvidedWithSetFilenameTest)
	{

		TEST(NoFilenameProvidedTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");
			myfile << "element11,element12\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;

			// Provide the filename through the SetFilename() function call
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::CsvTable csvTable;
			try
			{
				// Call ReadEntireFile() without providing filename
				csvTable = csvParser.ReadEntireFile();
				// Remove CSV filename now that we have finished reading it
				remove("test/test.csv");
			}
			catch(const char* msg)
			{
				std::cout << msg;
				return;
			}

			CHECK_EQUAL("element11", csvTable[0][0]);
			CHECK_EQUAL("element12", csvTable[0][1]);
			CHECK_EQUAL("element21", csvTable[1][0]);
			CHECK_EQUAL("element22", csvTable[1][1]);

			// Print out the CSV table for debug info
			uint32_t x, y;

			for(x = 0; x < csvTable.NumRecords(); x++)
			{
				for(y = 0; y < csvTable[x].NumFields(); y++)
				{
					std::cout << "csvTable[" << x << "][" << y << "] = " << csvTable[x][y] << std::endl;

				}
			}
		}
		
		TEST(FilenameProvidedToFunctionTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");
			myfile << "element11,element12\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;
			//csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::CsvTable csvTable;
			try
			{
				// Use the overload where the filename is provided.
				csvTable = csvParser.ReadEntireFile("test/test.csv");
				// Remove CSV filename now that we have finished reading it
				remove("test/test.csv");
			}
			catch(const char* msg)
			{
				std::cout << msg;
				return;
			}

			CHECK_EQUAL("element11", csvTable[0][0]);
			CHECK_EQUAL("element12", csvTable[0][1]);
			CHECK_EQUAL("element21", csvTable[1][0]);
			CHECK_EQUAL("element22", csvTable[1][1]);

			// Print out the CSV table for debug info
			uint32_t x, y;

			for(x = 0; x < csvTable.NumRecords(); x++)
			{
				for(y = 0; y < csvTable[x].NumFields(); y++)
				{
					std::cout << "csvTable[" << x << "][" << y << "] = " << csvTable[x][y] << std::endl;

				}
			}
		}

	} // SUITE(ReadEntireFileTests)
} // namespace CsvCppTest
