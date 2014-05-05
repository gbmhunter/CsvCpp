//!
//! @file 			CsvTable.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/05
//! @brief			Contains the CsvTable object, which represents a CSV file.
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/CsvTable.hpp"
#include "../include/CsvRecord.hpp"

namespace CsvCpp
{
	void CsvTable::AddRecord(CsvRecord record)
	{
		// Add the record to the end of the std::vector.
		this->recordV.push_back(record);
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
