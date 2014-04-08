//!
//! @file 			Record.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/08
//! @brief
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/Record.hpp"

namespace CsvCpp
{

	void Record::Add(std::string csvLine)
	{
		this->elementV.push_back(csvLine);
	}

	uint32_t Record::NumElements()
	{
		return this->elementV.size();
	}

}

// EOF
