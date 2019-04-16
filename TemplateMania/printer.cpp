#include "printer.hpp"
#include <iostream>

using namespace std;

template <typename T>
void Printer::print_item(T item)
{
    cout << item << endl;
}
