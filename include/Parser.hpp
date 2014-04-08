//!
//! @file 			Parser.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/08
//! @brief
//! @details
//!

#ifndef CSV_CPP_PARSER_H
#define CSV_CPP_PARSER_H

#include <string>
#include <vector>

#include "Row.hpp"
#include "Table.hpp"

namespace CsvCpp
{

	class Parser
	{
		public:

			//! @brief		Sets the filename for the CSV file.
			void SetFilename(std::string filename);

			//! @brief		Read a row from the CSV file
			Row ReadRow();

			//! @brief		Read an entire CSV file.
			//! @details	Calls ReadRow() many times.
			Table ReadEntireFile();

			//! @brief		What the parser will search for in the CSV files as a line delimiter.
			//! @details	Typically set to \r\n (CRLF) or just \n (LF).
			std::string lineDelimiter;

		private:

			std::string filename;

			Row ExtractElementsToRow(std::string csvRowString);

	};

}

#endif // #ifndef #ifndef CSV_CPP_PARSER_H

// EOF
