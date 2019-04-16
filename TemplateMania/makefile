#This is a make file. It is a file that makes things, you know.
#This is a make file for a c++ compiler and so,
CXX = g++
#let's set some flags for the compiler
CXXVERSION = -std=c++17

#What art thou programs
PROGRAMS = main

#The Target files now,
main: main.o printer.o
	$(CXX) -o main main.o printer.o


#Compile dependancies
main.o: main.cpp printer.hpp
	$(CXX) $(CXXVERSION) -c main.cpp

printer.o: printer.hpp
	$(CXX) $(CXXVERSION) -c printer.cpp


#This is to tidy up the place
.PHONY: clean
clean: 
	-rm $(PROGRAMS) *.o
