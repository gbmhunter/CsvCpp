//!
//! @file 			Log.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/07
//! @last-modified 	2014/04/09
//! @brief 			Contains logging functionality for debug and error messages.
//! @details
//!					See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef CSV_CPP_LOG_H
#define CSV_CPP_LOG_H

#include <sstream>

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace CsvCpp
{

	class Log
	{
	   private:

	   public:

		  Log()
	   	  {
			  // Make pointer NULL by default to we don't try an access dangling pointer
			  // if it hasn't been assigned
			  buff = NULL;
		  }

		  ~Log()
		  {
			 if(buff != NULL)
				 // Add an newline.
				 *buff << std::endl;
		  }

		  //! @brief		Pointer to an ostream buffer that serves as an output for logging messages.
		  //! @details		Defaults to NULL.
		  std::ostream* buff;

		  template<typename T>
		  Log &operator << (const T &t)
		  {
			 if(buff != NULL)
				  *buff << t;
			 return * this;
		  }

		  //! @brief		Special case overload so we can use std::endl.
		  Log& operator<<(std::ostream& (*f)(std::ostream&))
		  {
			  if(buff != NULL)
				  *buff << f;
			  return *this;
		  }
	};

	extern Log debugMsg;
	extern Log errorMsg;

} // namespace CsvCpp

#endif	// #ifndef CSV_CPP_LOG_H

// EOF
