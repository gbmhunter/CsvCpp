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

	void Record::AddField(std::string field)
	{
		this->fieldV.push_back(field);
	}

	uint32_t Record::NumFields()
	{
		return this->fieldV.size();
	}

}

// EOF
