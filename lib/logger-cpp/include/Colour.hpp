//!
//! @file 			Colour.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> ()
//! @created		2014/01/08
//! @last-modified 	2014/05/20
//! @brief
//! @details
//!					See README.rst in repo root dir for more info.

// Header guard
#ifndef LOGGER_COLOUR_H
#define LOGGER_COLOUR_H

// System headers
#include <string>

namespace Logger
{
	class Colour
	{

	public:

		//! @brief		Constructor.
		Colour(std::string name, std::string ansiCode);

		//! @brief		Copy constructor.
		Colour(const Colour& other);

		//! @brief		Name the the colour
		std::string name;

		//! @brief		The colours ANSI code
		std::string ansiCode;

	private:

		//==================================== PRIVATE VARIABLES ================================//


		//====================================== PRIVATE METHODS ================================//


	};

}

#endif // #ifndef LOGGER_COLOUR_H
