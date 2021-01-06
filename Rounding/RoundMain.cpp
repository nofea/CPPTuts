#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double d = -1.24;
    cout << d << endl;
    cout << floor(d) << endl;
    cout << ceil(d) << endl;
    cout << round(d) << endl;

    cout << floor(d + 0.5) << endl;

    d = -1.73;
    cout << d << endl;
    cout << floor(d) << endl;
    cout << ceil(d) << endl;
    cout << round(d) << endl;


    cout << floor(d + 0.5) << endl;

    return 0;
}
