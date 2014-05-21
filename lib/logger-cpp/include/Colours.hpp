//!
//! @file 			Colours.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> ()
//! @created		2014/01/08
//! @last-modified 	2014/05/20
//! @brief			The Sp (smart print) class adds colouring with easy-to-use ostream "<<" message printing functionality.
//! @details
//!					See README.rst in repo root dir for more info.

// Header guard
#ifndef LOGGER_COLOURS_H
#define LOGGER_COLOURS_H

#include "Config.hpp"
#include "Colour.hpp"

namespace Logger
{
/*
	class Colours
	{

	public:

		static const Colour normal = Colour("normal", config_TERM_TEXT_FORMAT_NORMAL);
		static const Colour white;
		static const Colour red;
		static const Colour yellow;
		static const Colour green;
		static const Colour blue;

	private:

		//==================================== PRIVATE VARIABLES ================================//


		//====================================== PRIVATE METHODS ================================//


	};*/

	namespace Colours
	{

		const Colour normal("normal", config_TERM_TEXT_FORMAT_NORMAL);

		// White is just the same as normal (uses the same ANSI code)
		const Colour white("white", config_TERM_TEXT_FORMAT_NORMAL);

		const Colour red("red", config_TERM_COLOUR_RED);
		const Colour green("green", config_TERM_COLOUR_GREEN);
		const Colour yellow("yellow", config_TERM_COLOUR_YELLOW);
		const Colour blue("blue", config_TERM_COLOUR_BLUE);
	}
}

#endif // #ifndef LOGGER_COLOURS_H
