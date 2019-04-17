CXX = g++
CXXVERSION = -std=c++11
PROGRAM = main

main: main.o LongestCommonPrefix.o
	$(CXX) -o main main.o LongestCommonPrefix.o

LongestCommonPrefix.o: LongestCommonPrefix.cpp LongestCommonPrefix.hpp

.PHONY: clean
clean: 
	-rm $(PROGRAM) *.o