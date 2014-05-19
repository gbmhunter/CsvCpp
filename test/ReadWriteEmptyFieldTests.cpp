//!
//! @file 			ReadWriteEmptyFieldTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/19
//! @last-modified 	2014/05/19
//! @brief
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(ReadWriteEmptyFieldTests)
	{

		TEST(EmptyFieldAtStartOfRecordTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");
			// Insert empty field at element21
			myfile << "element11,element12\n,element22";
			myfile.close();

			CsvCpp::Parser csvParser;
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::CsvTable csvTable;
			try
			{
				csvTable = csvParser.ReadEntireFile();
				remove("test/test.csv");
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
				// Something bad happened
				CHECK(false);
				return;
			}

			CHECK_EQUAL("element11", csvTable[0][0]);
			CHECK_EQUAL("element12", csvTable[0][1]);
			// Make sure this field is empty (two different methods)
			CHECK_EQUAL("", csvTable[1][0]);
			CHECK_EQUAL(true, csvTable[1][0].empty());

			CHECK_EQUAL("element22", csvTable[1][1]);

		}

		TEST(EmptyFieldAtEndOfRecordTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");
			// Insert empty field at element22
			myfile << "element11,element12\nelement21,";
			myfile.close();

			CsvCpp::Parser csvParser;
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::CsvTable csvTable;
			try
			{
				csvTable = csvParser.ReadEntireFile();
				remove("test/test.csv");
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
				// Something bad happened
				CHECK(false);
				return;
			}

			CHECK_EQUAL("element11", csvTable[0][0]);
			CHECK_EQUAL("element12", csvTable[0][1]);
			CHECK_EQUAL("element21", csvTable[1][0]);

			// Make sure this field is empty (two different methods)
			CHECK_EQUAL("", csvTable[1][1]);
			CHECK_EQUAL(true, csvTable[1][1].empty());

		}

		TEST(EmptyFieldsEverywhereTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");
			// Insert empty fields everywhere
			myfile << ",\n,";
			myfile.close();

			CsvCpp::Parser csvParser;
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::CsvTable csvTable;
			try
			{
				csvTable = csvParser.ReadEntireFile();
				remove("test/test.csv");
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
				// Something bad happened
				CHECK(false);
				return;
			}

			// Make sure all fields are empty
			CHECK_EQUAL("", csvTable[0][0]);
			CHECK_EQUAL("", csvTable[0][1]);
			CHECK_EQUAL("", csvTable[1][0]);
			CHECK_EQUAL("", csvTable[1][1]);

		}

	} // SUITE(ReadWriteEmptyFieldTests)
} // namespace CsvCppTest
