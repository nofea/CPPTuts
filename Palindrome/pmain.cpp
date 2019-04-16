#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(int x) 
{
    string sNum, sReverseNum;
    unsigned int iNumLength;

    sReverseNum = sNum = to_string(x);
    iNumLength = sNum.length();

    for(int i = 0; i < iNumLength; i++)
    {
        sReverseNum.at(i) = sNum.at((iNumLength - 1) - i);
    }
    if(sReverseNum == sNum) {return true;}
    return false;
}

int main(int argc, char *argv[])
{
    cout << "The Number is a " << isPalindrome(atoi(argv[argc - 1])) << endl;
    return 0;
}