//!
//! @file 			EmptyFileTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/05
//! @last-modified 	2014/05/06
//! @brief 			Makes sure the Parser can read from an empty file safely.
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(EmptyFileTests)
	{

		TEST(EmptyFileTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");
			//myfile << "element11,element12\nelement21,element22";
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
			catch(std::exception& e)
			{
				std::cout << e.what();
				// Something bad happened
				CHECK(false);
				return;
			}

			// Empty file, there should be no record
			CHECK_EQUAL(0, csvTable.NumRecords());

			// Get status
			CsvCpp::Parser::Status csvStatus = csvParser.GetStatus(&csvTable);

			// Should not be well formed!!!
			CHECK_EQUAL(false, csvStatus.isWellformed);

		}

	} // SUITE(EmptyFileTests)
} // namespace CsvCppTest
