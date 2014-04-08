//!
//! @file 			Record.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com>
//! @created		2014/04/03
//! @last-modified 	2014/04/08
//! @brief
//! @details
//!

#ifndef CSV_RECORD_H
#define CSV_RECORD_H

#include <string>
#include <vector>

namespace CsvCpp
{

	class Record
	{
		public:

			//! @brief		Overload the [] operator to provide a specific field from the CSV record.
			std::string & operator[](std::size_t index)
			{
				return fieldV[index];
			}

			//! @brief		Adds a field to the end of the record.
			//! @details	Record fields can be accessed once added with the [] operator.
			void AddField(std::string field);

			//! @brief		Returns the number of fields in the record.
			uint32_t NumFields();

		private:
			//! @brief		Used to internally store the retrieved elements from a row in a CSV file.
			std::vector<std::string> fieldV;

	};
}

#endif // #ifndef CSV_RECORD_H

// EOF
