#include "printlist.hpp"

using namespace std;

void printlist(list<int>& numlist)
{
    for(list<int>::iterator it = numlist.begin(); it != numlist.end(); ++it)
    {
        cout << *it << endl;
    }
}