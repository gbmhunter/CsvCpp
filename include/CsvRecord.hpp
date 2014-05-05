//!
//! @file 			CsvRecord.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/05
//! @brief			Contains the Record object, which is used to represent a row of a CSV file.
//! @details
//!

#ifndef CSV_CPP_CSV_RECORD_H
#define CSV_CPP_CSV_RECORD_H

// System includes
#include <string>
#include <vector>
#include <stdint.h>

namespace CsvCpp
{

	//! @brief		A CsvRecord represents a row in a CSV file. Multiple CsvRecords make up a CsvTable, which can be read or written to/from a file.
	class CsvRecord
	{
		public:

			//! @brief		Overload the [] operator to provide a specific field from the CSV record.
			//! @throws		{const char*} if index is outside valid range.
			const std::string & operator[](std::size_t index) const;

			//! @brief		Overload the [] operator to provide a specific field from the CSV record.
			//! @throws		{const char*} if index is outside valid range.
			std::string & operator[](std::size_t index);

			//! @brief		Adds a field to the end of the record.
			//! @details	Record fields can be accessed once added with the [] operator.
			//! @throws		Does not throw.
			void AddField(std::string field);

			//! @brief		Removes the field at the specified 0-based index.
			//! @param		index The 0-based index of the field you wish to remove.
			//! @throws		{const char*} if index is outside valid range.
			void RemoveField(uint32_t elementIndex);

			//! @brief		Returns the number of fields in the record.
			//! @throws		Does not throw.
			uint32_t NumFields() const;

		private:
			//! @brief		Used to internally store the retrieved elements from a row in a CSV file.
			std::vector<std::string> fieldV;

	};
}

#endif // #ifndef CSV_CPP_CSV_RECORD_H

// EOF
