###########################################################################
##                                                                       ##
## Project: C++ addressbook.                                             ##
##                                                                       ##
## Description: Build addressbook                                        ##
##                                                                       ##
## Date: March 29, 2017.                                                 ##
##                                                                       ##
###########################################################################

##
## $Id$
##
## $Log$

.SUFFIXES:
.SUFFIXES: .c .cpp .o .y

MAKEFILE_DEPEND = .depend

LINK=g++ $^ -o $@
CFLAGS=-Wall -llibs/csvfile -Wextra -I.

.cpp.o:
	g++ -std=c++11 $(CFLAGS) -c $< -o $@

TARGETS = addressbook_main

all:	$(TARGETS)

test:
	make -C ./tests
	./tests/runTests

depend:
	g++ -MM *.cpp > $(MAKEFILE_DEPEND)

clean:
	rm -rf *.o libs/csvfile/*.o $(TARGETS) $(MAKEFILE_DEPEND) html latex

doc:
	doxygen -g
	doxygen

addressbook_main: addressbook.o libs/csvfile/csvfile.o libs/csvfile/common_utils.o libs/csvfile/convert_utf16.o addressbook_main.o
	$(LINK)

-include $(MAKEFILE_DEPEND)

## End of file 
