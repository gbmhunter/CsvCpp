//!
//! @file 			CsvRecord.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/05
//! @brief			Contains the CsvRecord object, which is used to represent a row of a CSV file.
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/CsvRecord.hpp"

namespace CsvCpp
{

	void CsvRecord::AddField(std::string field)
	{
		this->fieldV.push_back(field);
	}

	uint32_t CsvRecord::NumFields() const
	{
		return this->fieldV.size();
	}

}

// EOF
