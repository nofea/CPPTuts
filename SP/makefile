#This is a make file. It is a file that makes things, you know.
#This is a make file for a c++ compiler and so,
CXX = g++
#let's set some flags for the compiler
CXXVERSION = -std=c++14

#What art thou programs
PROGRAMS = main

#The Target files now,
main: spmain.o 
	$(CXX) -o main spmain.o

#Compile dependancies
spmain.o: spmain.cpp smartpointer.h
	$(CXX) $(CXXVERSION) -c spmain.cpp


#This is to tidy up the place
.PHONY: clean
clean: 
	-rm $(PROGRAMS) *.o
