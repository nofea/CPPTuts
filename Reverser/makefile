#This is a make file. It is a file that makes things, you know.
#This is a make file for a c++ compiler and so,
CXX = g++
#let's set some flags for the compiler
CXXVERSION = -std=c++17

#What art thou programs
PROGRAMS = main

#The Target files now,
main: rmain.o listreverser.o printlist.o
	$(CXX) -o main rmain.o listreverser.o printlist.o

#Compile dependancies
spmain.o: rmain.cpp listreverser.hpp printlist.hpp
	$(CXX) $(CXXVERSION) -c rmain.cpp

listreverser.o: listreverser.hpp
	$(CXX) $(CXXVERSION) -c listreverser.cpp

printlist.o: printlist.hpp
	$(CXX) $(CXXVERSION) -c printlist.cpp

#This is to tidy up the place
.PHONY: clean
clean: 
	-rm $(PROGRAMS) *.o
