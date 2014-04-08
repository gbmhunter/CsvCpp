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
#include "../include/Row.hpp"

namespace CsvCpp
{
	void Table::Add(Row row)
	{
		this->RowV.push_back(row);
	}

	uint32_t Table::NumRows()
	{
		return this->RowV.size();
	}

}

// EOF
