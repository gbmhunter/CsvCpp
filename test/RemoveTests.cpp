//!
//! @file 			RemoveTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/05
//! @last-modified 	2014/05/06
//! @brief 			Contains tests which remove elements from CsvRecord and CsvTable objects.
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(RemoveTests)
	{

		TEST(RemoveRecordTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvTable csvTable;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			csvTable.AddRecord(record);

			csvTable.RemoveRecord(0);

			// Make sure the Clear() call actually removed all records
			CHECK_EQUAL(0, csvTable.NumRecords());
		}

		TEST(RemoveRecordCauseExceptionTest)
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
				csvTable.RemoveRecord(1);
				// Should not get here!
				CHECK(false);
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}

			// Should still have the one record
			CHECK_EQUAL(1, csvTable.NumRecords());
		}

		TEST(RemoveFieldTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			record.RemoveField(0);

			// Make sure the Clear() call actually removed all records
			CHECK_EQUAL(1, record.NumFields());
		}

		TEST(RemoveFieldCauseExceptionTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::CsvRecord record;
			record.AddField("aaa");
			record.AddField("bbb");

			try
			{
				// 2 is outside range (0-1), should throw exception
				record.RemoveField(2);
				// Should not get here!
				CHECK(false);
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}

			// Should still have two fields
			CHECK_EQUAL(2, record.NumFields());
		}

	} // SUITE(RemoveTests)

} // namespace CsvCppTest

// EOF
