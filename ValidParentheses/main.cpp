#include <iostream>
#include "ValidParenthese.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    ValidParenthese VP;
    if(argc < 2) {return -1;}
    if(VP.isValid(argv[argc - 1]))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
    return 0;
}