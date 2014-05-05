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

	const std::string & CsvRecord::operator[](std::size_t index) const
	{
		// index is unsigned so no need to check for negatives
		if(index > this->fieldV.size() - 1)
			throw "Tried to access field outside range of field array.";

		return this->fieldV[index];
	}

	std::string & CsvRecord::operator[](std::size_t index)
	{
		// index is unsigned so no need to check for negatives
		if(index > this->fieldV.size() - 1)
			throw "Tried to access field outside range of field array.";

		return fieldV[index];
	}

	void CsvRecord::AddField(std::string field)
	{
		this->fieldV.push_back(field);
	}

	void CsvRecord::RemoveField(uint32_t elementIndex)
	{
		// Make sure index is in range
		if(elementIndex > (this->fieldV.size() - 1))
		{
			throw "Tried to remove field outside range of field array.";
		}

		this->fieldV.erase(this->fieldV.begin() + elementIndex);
	}

	uint32_t CsvRecord::NumFields() const
	{
		return this->fieldV.size();
	}

}

// EOF
