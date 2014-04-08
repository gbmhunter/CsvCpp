//!
//! @file 			Table.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/08
//! @brief
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/Table.hpp"
#include "../include/Record.hpp"

namespace CsvCpp
{
	void Table::Add(Record record)
	{
		this->recordV.push_back(record);
	}

	uint32_t Table::NumRecords()
	{
		return this->recordV.size();
	}

}

// EOF
