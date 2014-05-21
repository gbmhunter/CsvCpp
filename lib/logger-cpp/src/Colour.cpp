//!
//! @file 			Colour.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> ()
//! @created		2014/01/08
//! @last-modified 	2014/05/20
//! @brief
//! @details
//!					See README.rst in repo root dir for more info.

// System headers


// User headers
#include "../include/Colour.hpp"

namespace Logger
{
	Colour::Colour(std::string name, std::string ansiCode)
	{
		this->name = name;
		this->ansiCode = ansiCode;
	}

	Colour::Colour(const Colour& other)
	{
		// Copy everything using assignment operator
		this->name = other.name;
		this->ansiCode = other.ansiCode;
	}

}
