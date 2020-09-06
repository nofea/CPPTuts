#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream File;
    cout << "Hello World" << endl;
    File.open("lol.txt");
    File << "YOLO" << endl;
    File.close();
    return 0;
}