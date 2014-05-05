//!
//! @file 			CsvTable.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/05/05
//! @brief			Contains the CsvTable object, which represents a CSV file.
//! @details
//!

#ifndef CSV_CPP_CSV_TABLE_H
#define CSV_CPP_CSV_TABLE_H

#include <string>
#include <vector>

#include "CsvRecord.hpp"

namespace CsvCpp
{

	//! @brief		The CsvTable object represents a CSV file.
	class CsvTable
	{
		public:

			//! @brief		Overload the [] operator to provide a specific record from the CSV table.
			//! @note		Overloaded. This is the const overload.
			const CsvRecord & operator[](std::size_t index) const
			{
				return recordV[index];
			}

			//! @brief		Overload the [] operator to provide a specific record from the CSV table.
			//! @note		Overloaded. This is the non-const overload.
			CsvRecord & operator[](std::size_t index)
			{
				return recordV[index];
			}

			//! @brief		Adds a CSV record (i.e. a row) to the bottom of the table. Once records have been added they can be accessed
			//!				with the [] operator.
			//! @details	Find the total number of records by calling NumRecords().
			void AddRecord(CsvRecord record);

			//! @brief		Returns the number of records in the CSV table.
			uint32_t NumRecords() const;

			//! @brief		Deletes all records that belong to this table.
			void Clear();

		private:
			//! @brief		Used to internally store the records that make up the CSV table.
			std::vector<CsvRecord> recordV;

	};
}

#endif // #ifndef CSV_CPP_CSV_TABLE_H

// EOF
