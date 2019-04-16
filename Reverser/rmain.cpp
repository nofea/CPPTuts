#include <iostream>
#include "listreverser.hpp"
#include "printlist.hpp"

using namespace std;

int main()
{
    list<int> numlist = {0,1,2,3,4,5};
    auto it = numlist.begin();
    
    cout << "Input list:" << endl;
    printlist(numlist);


    cout << "Reverse List:" << endl;
    listreverse(it); 
    return 0;
}
