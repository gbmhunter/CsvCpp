//!
//! @file 			Config.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 		n/a
//! @created		2014/05/01
//! @last-modified 	2014/05/20
//! @brief 			Configuration file for the logger-cpp library.
//! @details
//!					See README.rst in repo root dir for more info.

//===============================================================================================//
//====================================== HEADER GUARD ===========================================//
//===============================================================================================//

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

#ifndef LOGGER_CPP_CONFIG_H
#define LOGGER_CPP_CONFIG_H


#define config_DEFAULT_FIELD_DELIMITER		","
#define config_DEFAULT_RECORD_DELIMITER		"\r\n"

#define config_TERM_TEXT_FORMAT_NORMAL 		"\x1B[0m"		//!< Returns text to normal formatting. Widely supported.
#define config_TERM_COLOUR_RED 				"\x1B[31;1m"	//!< Red text. Widely supported.
#define config_TERM_COLOUR_GREEN 			"\x1B[32;1m"	//!< Green text. Widely supported.
#define config_TERM_COLOUR_YELLOW 			"\x1B[33;1m"	//!< Yellow text. Widely supported.
#define config_TERM_COLOUR_BLUE 			"\x1B[34;1m"	//!< Blue text. Widely supported.

#define config_ADVANCED_TEXT_FORMATTING 			1
#define config_DEBUG_TEXT_COLOUR 					config_TERM_COLOUR_GREEN
#define config_ERROR_TEXT_COLOUR 					config_TERM_COLOUR_RED


#endif // #ifndef LOGGER_CPP_CONFIG_H

// EOF
