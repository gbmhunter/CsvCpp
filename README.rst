==============================================================
CsvCpp
==============================================================

--------------------------------------------------------------
Character-Seperated Values (CSV) Parser
--------------------------------------------------------------

.. image:: https://api.travis-ci.org/gbmhunter/CsvCpp.png?branch=master   
	:target: https://travis-ci.org/gbmhunter/CsvCpp

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- Created: 2014/04/07
- Last Modified: 2014/04/09
- Version: v2.0.1.0
- Company: CladLabs
- Project: Free Code Libraries
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

.. role:: bash(code)
	:language: bash

Description
===========

A C++ CSV (character-seperated value, also known as comma-seperated value) parser which can both decode/encode CSV files.

Powerful
--------

You can define what CsvCpp will use as a line delimiter (Parser::lineDelimiter).

Standards Compliant
-------------------

This CSV parsing library follows the speficiations and terminology of RFC 4180, which is accepted as the de-facto standard for CSV files.

Portable (Platform Agnostic)
----------------------------

CsvCpp can be used with ease on both Linux and embedded systems (as long as they are powerful enough to support strings and streams).

All platform-specific operations such as debug and error message printing are handled by providing you with pointer variables to assign to objects at run time.


Easy Including
--------------

All you need to do is include the single header file called :code:`CsvCpp.hpp` which is found in the :code:`api/` directory, and provide the compiler with all the files in the :code:`src/` directory.

Easy To Experiment With
-----------------------

CsvCpp comes with a Makefle with automatic dependcy tracking and example code which is automatically built on running the command :code:`make` from the root directory of the repo.

Once compiled, this example code can be run by typing :code:`example/Example.elf`.


Included Unit Tests
-------------------

CsvCpp used the UnitTest++ library to perform unit testing. They are located under :code:`test/`. The UnitTest++ library is included with this repo.

The unit tests check for:

- Basic funcitonality
- Various line delimiters


Installation
============

1. Clone the git repo onto your local storage.

2. Run :code:`make all` to compile and run unit tests. Do not worry about error messages being printed when unit tests are run, the unit tests are designed to specifically cause errors to test the response.

3. To include CsvCpp into your embedded (or otherwise) firmware/software project, copy the repo into your project folder (or other suitable place) and include the file :code:`/api/CsvCpp.hpp` from your C++ code.


Dependencies
============

The following table lists all of CsvCpp's dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
<iostream>             Standard C++ library std::cin, std::cout
<fstream>              Standard C++ library Writing to files using std::ofstream.
<cstdint>              Standard C++ library Fixed-width variable type definitions (e.g. uint32_t).
"UnitTest++"           /lib/UnitTest++      Unit test framework (test code in ./test/).
====================== ==================== ======================================================================


Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet!

Usage
=====

This is a basic example. See "example/" or "test/" for more examples. In main.cpp add...

::

	#include "api/CsvCpp.hpp"

	
	int main()
	{
	
	}
	
	
FAQ
===

Nothing yet...

Changelog
=========

========= ========== ===================================================================================================
Version    Date       Comment
========= ========== ===================================================================================================
v2.0.1.0  2014/04/09 Added safe guard if output logging stream pointers in the Log class are null, closes #9. Add relevant unit test. Removed slotmachine-cpp from the list of dependencies in README, closes #8.
v2.0.0.0  2014/04/08 Added ability to create a CSV file from a CsvCpp::Table object, closes #4. Added relevant unit test.
v1.1.1.0  2014/04/08 Added constructor for Parser class and set lineDelimiter to default to '\r\n'. Added ability for the user to specify the field delimiter, closes #5. Renamed 'elements' to 'fields', and 'rows' to 'records', to follow RFC 4180, closes #6. Added info to README about being standards complant.
v1.1.0.0  2014/04/08 Added portable logging capability (debug and error messages) with Log.hpp/.cpp. Added ability to specify the line delimiting characters in CsvCpp::Parser, closes #3. Added related unit tests for various types of delimiters. Added unit test for when the last line does not have the line delimiting character. Edited README. Parser no longer causes segmentation fault if last line does not have a line delimitier, closes #1. Unit tests no longer leave left-over test.csv files, closes #2.
v1.0.0.0  2014/04/07 Initial commit. Parser performs basic CSV file decoding into a CsvTable object. Basic unit test makes sure than the Parser object can read a simple CSV file correctly.
========= ========== ===================================================================================================