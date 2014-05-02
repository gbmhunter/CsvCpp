#
# @file 			Makefile
# @author 			Geoffrey Hunter <gbmhunter@gmail.com> (wwww.cladlab.com)
# @edited 			n/a
# @created			2014/04/07
# @last-modified 	2014/04/07
# @brief 			Makefile for Linux-based make, to compile the csv-cpp library, example code and run unit test code.
# @details
#					See README in repo root dir for more info.

# Define the compiler to use (e.g. gcc, g++)
#CC = g++

# Define any compile-time flags (e.g. -Wall, -g)
#CFLAGS = -Wall -g -std=c++0x

# Define any directories containing header files other than /usr/include.
# Prefix every directory with "-I" e.g. "-I./src/include"
#INCLUDES = -I./src/include

# Define library paths in addition to /usr/lib
# if I wanted to include libraries not in /usr/lib I'd specify
# their path using -Lpath, something like:
#LFLAGS = -L./lib/UnitTest++

# Define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
#LIBS = -lUnitTest++

SRC_CC := g++
SRC_OBJ_FILES := $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
SRC_LD_FLAGS := 
SRC_CC_FLAGS := -Wall -g -c -I./lib -std=c++0x

TEST_CC := g++
TEST_OBJ_FILES := $(patsubst %.cpp,%.o,$(wildcard test/*.cpp))
TEST_LD_FLAGS := 
TEST_CC_FLAGS := -Wall -g -c -I./lib -std=c++0x

EXAMPLE_CC := g++
EXAMPLE_OBJ_FILES := $(patsubst %.cpp,%.o,$(wildcard example/*.cpp))
EXAMPLE_LD_FLAGS := 
EXAMPLE_CC_FLAGS := -Wall -g -c -I./lib -std=c++0x

.PHONY: depend clean

# All
all: csvCppLib test example
	
	# Run unit tests:
	@./test/CsvCppTest.elf

#======== CSV-CPP LIB ==========	

csvCppLib : $(SRC_OBJ_FILES)
	# Make Clide library
	ar r libCsvCpp.a $(SRC_OBJ_FILES)
	
# Generic rule for src object files
src/%.o: src/%.cpp
	# Compiling src/ files
	$(SRC_CC) $(SRC_CC_FLAGS) -MD -o $@ $<
	-@cp $*.d $*.P >/dev/null 2>&1; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
		rm -f $*.d >/dev/null 2>&1

-include $(SRC_OBJ_FILES:.o=.d)
	
	
# ======== TEST ========
	
# Compiles unit test code
test : $(TEST_OBJ_FILES) | csvCppLib unitTestLib
	# Compiling unit test code
	g++ $(TEST_LD_FLAGS) -o ./test/CsvCppTest.elf $(TEST_OBJ_FILES) -L./lib/UnitTest++ -lUnitTest++ -L./ -lCsvCpp

# Generic rule for test object files
test/%.o: test/%.cpp
	# Compiling test/ files
	$(TEST_CC) $(TEST_CC_FLAGS) -MD -o $@ $<
	-@cp $*.d $*.P >/dev/null 2>&1; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
		rm -f $*.d >/dev/null 2>&1

-include $(TEST_OBJ_FILES:.o=.d)
	
unitTestLib:
	# Compile UnitTest++ library (has it's own Makefile)
	$(MAKE) -C ./lib/UnitTest++/ all
	
# ===== EXAMPLE ======

# Compiles example code
example : $(EXAMPLE_OBJ_FILES) csvCppLib
	# Compiling example code
	g++ $(EXAMPLE_LD_FLAGS) -o ./example/Example.elf $(EXAMPLE_OBJ_FILES) -L./ -lCsvCpp
	
# Generic rule for test object files
example/%.o: example/%.cpp
	$(EXAMPLE_CC) $(EXAMPLE_CC_FLAGS) -c -o $@ $<
	
# ====== CLEANING ======
	
clean: clean-ut clean-csv-cpp
	# Clean UnitTest++ library (has it's own Makefile)
	$(MAKE) -C ./lib/UnitTest++/ clean
	
clean-ut:
	@echo " Cleaning test object files..."; $(RM) ./test/*.o
	@echo " Cleaning test executable..."; $(RM) ./test/*.elf
	
clean-csv-cpp:
	@echo " Cleaning src object files..."; $(RM) ./src/*.o
	@echo " Cleaning src dependency files..."; $(RM) ./src/*.d
	@echo " Cleaning csv-cpp static library..."; $(RM) ./*.a
	@echo " Cleaning test object files..."; $(RM) ./test/*.o
	@echo " Cleaning test dependency files..."; $(RM) ./test/*.d
	@echo " Cleaning test executable..."; $(RM) ./test/*.elf
	@echo " Cleaning example object files..."; $(RM) ./example/*.o
	@echo " Cleaning example executable..."; $(RM) ./example/*.elf

	
