//!
//! @file 			Table.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/10
//! @brief
//! @details
//!

#ifndef CSV_TABLE_H
#define CSV_TABLE_H

#include <string>
#include <vector>

#include "Record.hpp"

namespace CsvCpp
{

	class Table
	{
		public:

			//! @brief		Overload the [] operator to provide a specific record from the CSV table.
			Record & operator[](std::size_t index)
			{
				return recordV[index];
			}

			//! @brief		Adds a CSV record (i.e. a row) to the bottom of the table. Once records have been added they can be accessed
			//!				with the [] operator.
			//! @details	Find the total number of records by calling NumRecords().
			void AddRecord(Record record);

			//! @brief		Returns the number of records in the CSV table.
			uint32_t NumRecords();

			//! @brief		Deletes all records that belong to this table.
			void Clear();

		private:
			//! @brief		Used to internally store the records that make up the CSV table.
			std::vector<Record> recordV;

	};
}

#endif // #ifndef CSV_TABLE_H

// EOF
