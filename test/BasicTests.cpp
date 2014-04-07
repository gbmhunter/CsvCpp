//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/07
//! @last-modified 	2014/04/07
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(BasicTests)
	{

		TEST(BasicTest)
		{
			std::ofstream myfile;
			myfile.open ("test/test.csv");
			myfile << "element11, element12\nelement21, element22";
			myfile.close();

			Csv::Parser csvParser;
			csvParser.SetFilename("test/test.csv");

			// Read back the entire file, file not exist, so within try/catch
			Csv::Table csvTable;
			try
			{
				csvTable = csvParser.ReadEntireFile();
			}
			catch(const char* msg)
			{
				std::cout << msg;
				return;
			}

			CHECK_EQUAL("element11", csvTable[0][0]);
			CHECK_EQUAL(" element12", csvTable[0][1]);
			CHECK_EQUAL("element21", csvTable[1][0]);
			CHECK_EQUAL(" element22", csvTable[1][1]);

			// Print out the CSV table for debug info
			uint32_t x, y;

			for(x = 0; x < csvTable.NumRows(); x++)
			{
				for(y = 0; y < csvTable.NumColumns(); y++)
				{
					//std::cout << "csvTable[" << x << "][" << y << "] = " << csvTable[x][y] << std::endl;

				}
			}


		}
		
	} // SUITE(BasicTests)
} // namespace CsvCppTest
