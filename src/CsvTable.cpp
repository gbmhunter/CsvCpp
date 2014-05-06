//!
//! @file 			CsvTable.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/06
//! @brief			Contains the CsvTable object, which represents a CSV file.
//! @details
//!

// Standard libs
#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdexcept>

// User source
#include "../include/CsvTable.hpp"
#include "../include/CsvRecord.hpp"

namespace CsvCpp
{

	const CsvRecord & CsvTable::operator[](std::size_t index) const
	{
		// index is unsigned so no need to check for negatives
		if(index > this->recordV.size() - 1)
			throw std::range_error("Tried to access record outside range of record array.");

		return this->recordV[index];
	}

	CsvRecord & CsvTable::operator[](std::size_t index)
	{
		// index is unsigned so no need to check for negatives
		if(index > this->recordV.size() - 1)
			throw std::range_error("Tried to access record outside range of record array.");

		return this->recordV[index];
	}


	void CsvTable::AddRecord(CsvRecord record)
	{
		// Add the record to the end of the std::vector.
		this->recordV.push_back(record);
	}

	void CsvTable::RemoveRecord(uint32_t index)
	{
		// Make sure index is in range
		if(index > this->recordV.size() - 1)
			throw std::range_error("Tried to remove record outside range of record array.");

		this->recordV.erase(this->recordV.begin() + index);
	}

	uint32_t CsvTable::NumRecords() const
	{
		// Return the size of the vector which holds the records
		return this->recordV.size();
	}

	void CsvTable::Clear()
	{
		// Clear the vector which holds the records
		this->recordV.clear();
	}

}

// EOF
