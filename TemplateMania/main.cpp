#include "printer.hpp"
#include <iostream>

using namespace std;


int main()
{
    Printer p;
    int inum = 12;
    double dnum = 12.67;
    char cthings = '12';
    string sthings = "12";

    p.print_item(inum);
    return 0;
}
