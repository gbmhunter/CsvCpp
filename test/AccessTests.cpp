//!
//! @file 			AccessTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/05
//! @last-modified 	2014/05/06
//! @brief 			Contains tests which which makes sure access to CsvRecord and CsvTable objects is safe (i.e. accessing out-of-range elements).
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(AccessTests)
	{

		TEST(FieldPositiveOutOfRangeTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			try
			{
				// Try an access an out-of-range element
				std::string myString = record[2];
				// Should never get here!
				CHECK(false);
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}

		}

		TEST(FieldNegativeOutOfRangeTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			try
			{
				// Try an access an out-of-range element
				std::string myString = record[-1];
				// Should never get here!
				CHECK(false);
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}

		}

		TEST(RecordPositiveOutOfRangeTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvTable csvTable;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			csvTable.AddRecord(record);

			try
			{
				// Remove a record that is out of range, should throw exception
				CsvCpp::CsvRecord myRecord = csvTable[1];
				// Should not get here!
				CHECK(false);
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		TEST(RecordNegativeOutOfRangeTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvTable csvTable;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			csvTable.AddRecord(record);

			try
			{
				// Remove a record that is out of range, should throw exception
				CsvCpp::CsvRecord myRecord = csvTable[-1];
				// Should not get here!
				CHECK(false);
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

	} // SUITE(AccessTests)

} // namespace CsvCppTest

// EOF
