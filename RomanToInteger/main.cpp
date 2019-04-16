#include <iostream>
#include "RomanNumeralDictionary.hpp"
using namespace std;


int main(int argc, char const *argv[])
{
    RomanNumeralDictionary RomanNumDict;

    if(argc > 2){return -1;}

    cout << RomanNumDict.getInteger(string(argv[argc-1])) << endl;
    return 0;
}