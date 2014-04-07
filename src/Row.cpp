//!
//! @file 			Row.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/03
//! @brief
//! @details
//!

#include <iostream>
#include <fstream>

#include "../include/Row.hpp"

namespace Csv
{

	void Row::Add(std::string csvLine)
	{
		this->elementV.push_back(csvLine);
	}

	uint32_t Row::NumElements()
	{
		return this->elementV.size();
	}

}

// EOF
