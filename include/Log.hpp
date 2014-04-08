//!
//! @file 			Log.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/04/07
//! @last-modified 	2014/04/08
//! @brief 			Contains callbacks for port-specific print operations.
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

	// An example with a string stream.
	class Log
	{
	   private:

	   public:

		  Log(){}
		  ~Log()
		  {
			 // Add an newline.
			 *buff << std::endl;
		  }
		  //! @brief		Pointer to an ostream buffer that
		  std::ostream* buff;

		  template<typename T>
		  Log &operator << (const T &t)
		  {
			 *buff << t;
			 return * this;
		  }
	};

	extern Log debugMsg;
	extern Log errorMsg;

} // namespace CsvCpp

#endif	// #ifndef CSV_CPP_LOG_H

// EOF
