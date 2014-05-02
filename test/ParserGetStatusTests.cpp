//!
//! @file 			ParserGetStatusTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/02
//! @last-modified 	2014/05/02
//! @brief 			Contains tests using the Parser::GetStatus() function.
//! @details
//!					See README.rst in root dir for more info.

// System includes
#include <iostream>
#include <fstream>
#include <cstdint>

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User includes
#include "../api/CsvCpp.hpp"

namespace CsvCppTest
{
	SUITE(ParserGetStatusTests)
	{

		TEST(RecordFieldsEqualTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with a non-even number of fields
			myfile << "element11,element12\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;

			// Provide the filename through the SetFilename() function call
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::Table csvTable;
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status.allRecordsHaveEqualNumFields is true
			CHECK_EQUAL(true, *(csvParser.GetStatus(&csvTable).allRecordsHaveEqualNumFields));

		}

		TEST(RecordFieldsNotEqualTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with a non-even number of fields
			myfile << "element11,element12,element13\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;

			// Provide the filename through the SetFilename() function call
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::Table csvTable;
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

			// Make sure status.allRecordsHaveEqualNumFields is false
			CHECK_EQUAL(false, *(csvParser.GetStatus(&csvTable).allRecordsHaveEqualNumFields));
			// Because of unequal fields counts, the table should not be wellformed!
			CHECK_EQUAL(false, *(csvParser.GetStatus(&csvTable).isWellformed));
		}

		TEST(NumRecordsTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with a non-even number of fields
			myfile << "element11,element12\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;

			// Provide the filename through the SetFilename() function call
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::Table csvTable;
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status.numRecords is equal to the number of records we created
			// in test.csv
			CHECK_EQUAL(2, *(csvParser.GetStatus(&csvTable).numRecords));

		}

		TEST(ValidNumFieldsTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with a non-even number of fields
			myfile << "element11,element12\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;

			// Provide the filename through the SetFilename() function call
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::Table csvTable;
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status.numFields is equal to the number of records we created
			// in test.csv
			if(csvParser.GetStatus(&csvTable).numFields)
			{
				CHECK_EQUAL(2, *(csvParser.GetStatus(&csvTable).numFields));
			}
			else
				// Should never get here!
				CHECK(false);

		}

		TEST(InvalidNumFieldsTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with a non-even number of fields
			myfile << "element11,element12,element13\nelement21,element22";
			myfile.close();

			CsvCpp::Parser csvParser;

			// Provide the filename through the SetFilename() function call
			csvParser.SetFilename("test/test.csv");
			csvParser.recordDelimiter = "\n";

			// Read back the entire file, file not exist, so within try/catch
			CsvCpp::Table csvTable;
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status.numFields is uninitialised, since the number of fields vary,
			// this value should be invalid
			if(csvParser.GetStatus(&csvTable).numFields)
			{
				// Fail if we got here!
				CHECK(false);
			}

			// Pass if we got here!
			CHECK(true);
		}


	} // SUITE(ParserGetStatusTests)
} // namespace CsvCppTest

// EOF
