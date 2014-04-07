//!
//! @file 			Parser.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/03
//! @brief
//! @details
//!

#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <vector>

#include "Row.hpp"
#include "Table.hpp"

namespace Csv
{

	class Parser
	{
		public:

			//! @brief		Sets the filename for the CSV file.
			void SetFilename(std::string filename);

			//! @brief		Read a row from the CSV file
			Row ReadRow();

			Table ReadEntireFile();

		private:

			std::string filename;

			Row ExtractElementsToRow(std::string csvRowString);

	};

}

#endif // #ifndef CSV_PARSER_H

// EOF
