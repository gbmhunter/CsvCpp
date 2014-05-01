//!
//! @file 			CreateCsvFileTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/08
//! @last-modified 	2014/05/01
//! @brief 			Tests the CSV file creation ability of the Parser object.
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(CreateCsvFileTests)
	{

		TEST(CreateCsvFileWithoutOverloadTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::Parser csvParser;
			CsvCpp::Table csvTable;

			CsvCpp::Record record1;
			record1.AddField("element11");
			record1.AddField("element12");
			csvTable.AddRecord(record1);

			CsvCpp::Record record2;
			record2.AddField("element21");
			record2.AddField("element22");
			csvTable.AddRecord(record2);

			// Create CSV file, passing the filename in instead of using SetFilename().
			csvParser.CreateCsvFile(csvTable, "test/output.csv");

			// Now read back the file so that we can check it is correct
			std::ifstream myIfStream("test/output.csv", std::ifstream::in);

			if ( (myIfStream.rdstate() & std::ifstream::failbit ) != 0 )
			{
				std::cout << "Error opening '" << "test/output.csv" << "'\n";
				throw "Couldn't open file.\r\n";
			}

			// Read the entire file stream into a string so we can a direct match with it
			std::istreambuf_iterator<char> eos;
			std::string theEntireFile(std::istreambuf_iterator<char>(myIfStream), eos);

			// Check that the file is correct
			CHECK_EQUAL("element11,element12\r\nelement21,element22\r\n", theEntireFile);

			// Close the input stream so we can delete the file
			myIfStream.close();

			// Now delete the file
			remove("test/output.csv");
		}

		TEST(CreateCsvFileWithOverloadTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::Parser csvParser;
			CsvCpp::Table csvTable;

			CsvCpp::Record record1;
			record1.AddField("element11");
			record1.AddField("element12");
			csvTable.AddRecord(record1);

			CsvCpp::Record record2;
			record2.AddField("element21");
			record2.AddField("element22");
			csvTable.AddRecord(record2);

			// Set the filename
			csvParser.SetFilename("test/output.csv");

			// Create CSV file, calling overloaded CreateCsvFile().
			csvParser.CreateCsvFile(csvTable);

			// Now read back the file so that we can check it is correct
			std::ifstream myIfStream("test/output.csv", std::ifstream::in);

			if ( (myIfStream.rdstate() & std::ifstream::failbit ) != 0 )
			{
				std::cout << "Error opening '" << "test/output.csv" << "'\n";
				throw "Couldn't open file.\r\n";
			}

			// Read the entire file stream into a string so we can a direct match with it
			std::istreambuf_iterator<char> eos;
			std::string theEntireFile(std::istreambuf_iterator<char>(myIfStream), eos);

			// Check that the file is correct
			CHECK_EQUAL("element11,element12\r\nelement21,element22\r\n", theEntireFile);

			// Close the input stream so we can delete the file
			myIfStream.close();

			// Now delete the file
			remove("test/output.csv");
		}

	} // SUITE(CreateCsvFileTests)

} // namespace CsvCppTest
