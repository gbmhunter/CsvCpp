//!
//! @file				Log.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created			2014/04/07
//! @last-modified		2014/05/20
//! @brief 				Contains logging functionality for debug and error messages.
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdio.h>		// snprintf()
#include <stdlib.h>		// realloc(), malloc(), free()
#include <cctype>		// isalnum() 

// User includes
#include "../include/Log.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Logger
{
/*
	const Colour Colours::normal("normal", config_TERM_TEXT_FORMAT_NORMAL);

	// White is just the same as normal (uses the same ANSI code)
	const Colour Colours::white("white", config_TERM_TEXT_FORMAT_NORMAL);

	const Colour Colours::red("red", config_TERM_COLOUR_RED);
	const Colour Colours::green("green", config_TERM_COLOUR_GREEN);
	const Colour Colours::yellow("yellow", config_TERM_COLOUR_YELLOW);
	const Colour Colours::blue("blue", config_TERM_COLOUR_BLUE);*/
}
