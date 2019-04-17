#include <iostream>
#include <vector>
#include "LongestCommonPrefix.hpp"
using namespace std;

int main()
{
    LongestCommonPrefix LCP;
    vector<string> vect = {"ye","olo","yale"};
    cout << LCP.getLongestCommonPrefix(vect) << endl;
    return 0;
}