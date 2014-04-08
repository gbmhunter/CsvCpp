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

			//! @brief		Overload the [] operator to provide a specific element from the CSV row.
			std::string & operator[](std::size_t index)
			{
				return elementV[index];
			}

			//! @brief		Adds a element to the end of the row.
			//! @details	Row elements can be accessed once added with the [] operator.
			void Add(std::string element);

			//! @brief		Returns the number of elements in the row.
			uint32_t NumElements();

		private:
			//! @brief		Used to internally store the retrieved elements from a row in a CSV file.
			std::vector<std::string> elementV;

	};
}

#endif // #ifndef CSV_RECORD_H

// EOF
