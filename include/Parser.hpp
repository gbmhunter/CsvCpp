//!
//! @file 			Parser.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/01
//! @brief			CSV file parser, which can both decode and encode CSV files.
//! @details
//!

#ifndef CSV_CPP_PARSER_H
#define CSV_CPP_PARSER_H

#include <string>
#include <vector>

#include "Record.hpp"
#include "Table.hpp"

namespace CsvCpp
{

	class Parser
	{
		public:

			//! @brief		Constructor.
			Parser();

			//! @brief		Sets the filename for the CSV file.
			void SetFilename(std::string filename);

			//! @brief		Read a record from the CSV file
			Record ReadRecord();

			//! @brief		Read an entire CSV file. Simplified overload, uses filename set with SetFilename().
			//! @details	Calls ReadRecord() many times.
			Table ReadEntireFile();

			//! @brief		Read an entire CSV file, using provided file name. Base overload.
			//! @details	Calls ReadRecord() many times.
			Table ReadEntireFile(std::string fileName);

			//! @brief		Creates a CSV file from the given Table object, and the provided filename.
			//! @param		table		A CsvCpp::Table object to create the CSV file from.
			//! @param		fileName	The filename of the CSV file to create.
			//! @note		Overloaded (this is the base function the others call).
			void CreateCsvFile(Table csvTable, std::string fileName);

			//! @brief		Creates a CSV file from the given Table object.
			//! @param		table		A CsvCpp::Table object to create the CSV file from.
			//! @note		Overloaded.
			void CreateCsvFile(Table csvTable);

			//! @brief		What the parser will search for in the CSV files as a record delimiter.
			//! @details	Typically set to "\r\n" (CRLF) or just "\n" (LF). Defaults to "\r\n".
			std::string recordDelimiter;

			//! @brief		The character sequence to use as the field delimiter when parsing CSV files.
			//! @details	Typically set to "," (comma-separated values) or the tab character. Defaults to ",".
			std::string fieldDelimiter;

		private:

			//! @brief		Holds the filename of the file that the parser will operate on if functions like
			//!				ReadEntireFile() or ReadRecord() are called.
			std::string filename;

			//! @brief		Converts a line of the CSV file in string format to a Record object.
			Record RecordStringToRecord(std::string csvRowString);

	};

}

#endif // #ifndef #ifndef CSV_CPP_PARSER_H

// EOF
