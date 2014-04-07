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
- Last Modified: 2014/04/07
- Version: v1.0.0.0
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

Portable (Platform Agnostic)
----------------------------

CsvCpp can be used with ease on both Linux and embedded systems. All platform-specific operations are handled via callbacks that you provide the functionality for (e.g. printing to the command line and printing debug information). These callbacks exist in Print.hpp/.cpp.


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

Event-driven Callback Support
-----------------------------

CsvCpp leverages the slotmachine-cpp library to provide event-driven callbacks. slotmachine-cpp supports callbacks to methods (instance functions), without CsvCpp having any previous knowledge about the class (type agnostic).

List of events supported by callbacks:

- None yet!


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
"SlotMachine.hpp"      /lib/slotmachine-cpp Method callback functionality
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
v1.0.0.0  2014/04/07 Initial commit. Parser performs basic CSV file decoding into a CsvTable object. Basic unit test makes sure than the Parser object can read a simple CSV file correctly.
========= ========== ===================================================================================================