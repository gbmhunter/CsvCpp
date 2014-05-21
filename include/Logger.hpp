//!
//! @file 			Logger.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/05/20
//! @last-modified 	2014/05/20
//! @brief
//! @details		Contains definitions for the global logger objects.
//!

#ifndef CSV_CPP_LOGGER_H
#define CSV_CPP_LOGGER_H

// System includes
#include <string>
#include <vector>
#include <stdint.h>

// User libraries
#include "../lib/logger-cpp/include/Log.hpp"

namespace CsvCpp
{

	extern Logger::Log debugMsg;
	extern Logger::Log errorMsg;
}

#endif // #ifndef CSV_CPP_LOGGER_H

// EOF
