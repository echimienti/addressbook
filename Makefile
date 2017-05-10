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

.cpp.o:
	g++ -std=c++11 -Wall -Wextra -I. -c $< -o $@

TARGETS =
TARGETS += addressbook_main

all:	$(TARGETS)

test:
	make -C ./tests
	./tests/runTests

depend:
	g++ -MM *.cpp > $(MAKEFILE_DEPEND)

clean:
	rm -rf *.o $(TARGETS) $(MAKEFILE_DEPEND) html latex

doc:
	doxygen -g
	doxygen

addressbook_main: addressbook.o libcsvfile/csvfile.o addressbook_main.o
	$(LINK)

-include $(MAKEFILE_DEPEND)

## End of file 

	
