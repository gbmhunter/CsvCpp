//!
//! @file 			Table.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/10
//! @brief
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/Table.hpp"
#include "../include/Record.hpp"

namespace CsvCpp
{
	void Table::AddRecord(Record record)
	{
		// Add the record to the end of the std::vector.
		this->recordV.push_back(record);
	}

	uint32_t Table::NumRecords()
	{
		// Return the size of the vector which holds the records
		return this->recordV.size();
	}

	void Table::Clear()
	{
		// Clear the vector which holds the records
		this->recordV.clear();
	}

}

// EOF
