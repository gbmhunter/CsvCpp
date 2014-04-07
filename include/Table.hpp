//!
//! @file 			Table.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/03
//! @brief
//! @details
//!

#ifndef CSV_TABLE_H
#define CSV_TABLE_H

#include <string>
#include <vector>

#include "Row.hpp"

namespace Csv
{

	class Table
	{
		public:

			//! @brief		Overload the [] operator to provide a specific row from the CSV table.
			Row & operator[](std::size_t index)
			{
				return RowV[index];
			}

			//! @brief		Adds a row to the bottom of the table. Once rows have been added they can be accessed
			//!				with the [] operator.
			//! @details	Find the total number of rows by calling NumRows().
			void Add(Row row);

			//! @brief		Returns the number of rows in the CSV table.
			uint32_t NumRows();

			//! @brief		Returns the number of columns in the CSV table.
			uint32_t NumColumns();

		private:
			//! @brief		Used to internally store the rows in a CSV file.
			std::vector<Row> RowV;

	};
}

#endif // #ifndef CSV_TABLE_H

// EOF
