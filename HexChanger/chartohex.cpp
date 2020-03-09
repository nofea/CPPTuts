#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string hexstring("0XD8");
    int hexNumber = 0;

    stringstream ss;

    ss << hexstring;

    ss >> hex >> hexNumber;

     cout << hexNumber << endl;  

    return 0;
}
 