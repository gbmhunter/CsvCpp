//!
//! @file 			CsvTable.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/06
//! @brief			Contains the CsvTable object, which represents a CSV file.
//! @details
//!

#ifndef CSV_CPP_CSV_TABLE_H
#define CSV_CPP_CSV_TABLE_H

// Standard libraries
#include <string>
#include <vector>

// User source
#include "CsvRecord.hpp"

namespace CsvCpp
{

	//! @brief		The CsvTable object represents a CSV file.
	class CsvTable
	{
		public:

			//! @brief		Overload the [] operator to provide a specific record from the CSV table.
			//! @throws		{std::range_error} if index is outside valid range.
			//! @note		Overloaded. This is the const overload.
			const CsvRecord & operator[](std::size_t index) const;

			//! @brief		Overload the [] operator to provide a specific record from the CSV table.
			//! @throws		{std::range_error} if index is outside valid range.
			//! @note		Overloaded. This is the non-const overload.
			CsvRecord & operator[](std::size_t index);

			//! @brief		Adds a CSV record (i.e. a row) to the bottom of the table. Once records have been added they can be accessed
			//!				with the [] operator.
			//! @details	Find the total number of records by calling NumRecords().
			//! @throws		Does not throw.
			void AddRecord(CsvRecord record);

			//! @brief		Removes the record at the specified 0-based index.
			//! @param		index The 0-based index of the record you wish to remove.
			//! @throws		{std::range_error} if index is outside valid range.
			void RemoveRecord(uint32_t index);

			//! @brief		Returns the number of records in the CSV table.
			//! @returns	The number of records in the table.
			//! @throws		Does not throw.
			uint32_t NumRecords() const;

			//! @brief		Deletes all records that belong to this table.
			//! @throws		Does not throw.
			void Clear();

		private:

			//! @brief		Used to internally store the records that make up the CSV table.
			std::vector<CsvRecord> recordV;

	};
}

#endif // #ifndef CSV_CPP_CSV_TABLE_H

// EOF
