#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileIO;

    fileIO.open("File.txt", ios::in | ios::out);

    fileIO << "yolo" << endl;

    fileIO.close();

    return 0;
}