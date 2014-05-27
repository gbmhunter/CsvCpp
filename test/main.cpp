//!
//! @file 			main.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/07
//! @last-modified 	2014/05/27
//! @brief 			Contains main entry point for unit tests.
//! @details
//!					See README.rst in root dir for more info.

// System includes
#include <iostream>

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"
#include "../lib/UnitTest++/src/TestReporterStdout.h"

// User source
#include "../api/CsvCpp.hpp"

int main()
{

	//std::cout << "TESTING" << std::endl;
	//while(1);
	// Run all tests. Comment this out and run code below if you only
	// want to run particular tests
	return UnitTest::RunAllTests();
	
	try
    {
        UnitTest::TestReporterStdout reporter;
		UnitTest::TestRunner runner(reporter);
	
	
		return runner.RunTestsIf(
			UnitTest::Test::GetTestList(),
			"CreateCsvFileTests",			// Enter a test suite name here to only run those tests
			UnitTest::True(),
			0);
    }
    catch(std::exception const& e)
    {
         printf("%s", e.what());
         // If you are feeling mad (not in main) you could rethrow! 
    }
	
}
