//!
//! @file 			CsvRecord.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/05/20
//! @last-modified 	2014/05/27
//! @brief			Contains definitions for the global logger objects.
//! @details
//!

// System libraries
#include <iostream>
#include <fstream>
#include <stdexcept> // Use of std::range_error class for exceptions.

// User libraries
#include "lib/logger-cpp/api/LoggerApi.hpp"

// User source
#include "../include/Logger.hpp"

namespace CsvCpp
{
	LoggerNs::Colour testColour;

	// Global logger object definitions
	LoggerNs::Logger debugMsg(std::cout, LoggerNs::Colours::DARK_YELLOW(), LoggerNs::Colours::DEFAULT());
	//LoggerNs::Logger debugMsg(std::cout, testColour, testColour);
	LoggerNs::Logger errorMsg(std::cout, LoggerNs::Colours::DARK_RED(), LoggerNs::Colours::DEFAULT());
	//LoggerNs::Logger errorMsg(std::cout, testColour, testColour);

}

// EOF
