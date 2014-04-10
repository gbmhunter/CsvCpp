//!
//! @file 			TableTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/10
//! @last-modified 	2014/04/10
//! @brief 			Contains tests relating to the Table object.
//! @details
//!					See README.rst in root dir for more info.

#include <iostream>
#include <fstream>
#include <cstdint>

#include "../api/CsvCpp.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace CsvCppTest
{
	SUITE(TableTests)
	{

		TEST(ClearRecordTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			CsvCpp::Table csvTable;

			CsvCpp::Record record;
			record.AddField("aaa");
			record.AddField("bbb");

			csvTable.AddRecord(record);

			csvTable.Clear();

			// Make sure the Clear() call actually removed all records
			CHECK_EQUAL(0, csvTable.NumRecords());
		}

	} // SUITE(TableTests)

} // namespace CsvCppTest

// EOF
