//!
//! @file 			CsvRecord.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/05/20
//! @last-modified 	2014/05/20
//! @brief			Contains definitions for the global logger objects.
//! @details
//!

// System libraries
#include <iostream>
#include <fstream>
#include <stdexcept> // Use of std::range_error class for exceptions.

// User libraries
#include "../lib/logger-cpp/include/Log.hpp"

// User source
#include "../include/Logger.hpp"

namespace CsvCpp
{
	// Global logger object definitions
	Logger::Log debugMsg(Logger::Colours::yellow);
	Logger::Log errorMsg(Logger::Colours::red);

}

// EOF
