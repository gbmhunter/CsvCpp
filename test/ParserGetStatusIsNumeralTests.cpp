//!
//! @file 			ParserGetStatusIsNumeralTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/05/19
//! @last-modified 	2014/05/19
//! @brief 			Contains tests using the Parser::Status::allFieldsNumeral variable.
//! @details
//!					See README.rst in root dir for more info.

// System includes
#include <iostream>		// std::cout
#include <fstream>		// ofstream
#include <cstdint>		// uint32_t...

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User includes
#include "../api/CsvCpp.hpp"

namespace CsvCppTest
{
	SUITE(ParserGetStatusIsNumeralTests)
	{

		TEST(IsNumeralTrueTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12,34\n56,78\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are numeral
			CHECK_EQUAL(true, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralNegativeIntegersTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12,-34\n-56,78\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are numeral
			CHECK_EQUAL(true, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralDoublesTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12.45,-34.67\n-56.11,78.00\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are numeral
			CHECK_EQUAL(true, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralExponentialTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12.45e2,-34.67\n-56.11e-23,78.00\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are numeral
			CHECK_EQUAL(true, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralHexidecimalTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "0x00,0x02\n0xFF,0xD8\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are numeral
			CHECK_EQUAL(true, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseTest1)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12,34\n5a6,78\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseTest2)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12,34a\n56,78\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseTest3)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with all fields being numeral
			myfile << "12,34\n56,0xFG\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseTest4)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with "numeral" with two decimal points
			myfile << "12.2,34.7\n-56..2,23.6\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseTwoNegativeSignsTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with "numeral" with two decimal points
			myfile << "12.2,34.7\n--56.2,23.6\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseEmptyFieldTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with one field being empty
			myfile << "12.2,34.7\n,23.6\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

		TEST(IsNumeralFalseSpaceInFieldTest)
		{
			// Connect up error and debug streams
			CsvCpp::debugMsg.buff = &std::cout;
			CsvCpp::errorMsg.buff = &std::cout;

			std::ofstream myfile;
			myfile.open("test/test.csv");

			// Create records with one field being empty
			myfile << "12.2,34.7\n ,23.6\n";
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

			CsvCpp::Parser::Status status = csvParser.GetStatus(&csvTable);

			// Make sure status object indicates all fields are NOT numeral
			CHECK_EQUAL(false, *(status.allFieldsNumeral));

		}

	} // SUITE(ParserGetStatusIsNumeralTests)
} // namespace CsvCppTest

// EOF
