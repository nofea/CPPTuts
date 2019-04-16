#include<iostream>
#include<string>
#include<limits>

using namespace std;


int reverse(int x)
{
    int iSol = 0;
    string sReverseNum,sNum = to_string(x); 

    sReverseNum = sNum;
    
    unsigned int iNumLength = sNum.length();

    if(sNum.at(0) == '-')
    {
        sReverseNum.at(0) = sNum.at(0);
        for(int i = 1; i < iNumLength; i++)
        {
            sReverseNum.at(i) = sNum.at(iNumLength - i);
        }
    }
    else
    {
        for(int i = 0; i < iNumLength; i++)
        {
            sReverseNum.at(i) = sNum.at((iNumLength - 1) - i);
        }
    }
    
    if ((stol(sReverseNum) > INT32_MAX) || (stol(sReverseNum)) < INT32_MIN) { return 0; }
    iSol = stoi(sReverseNum);
    return iSol;
}

int main(int argc, char const *argv[])
{
    cout << "arg1: " << argc << endl;
    cout << "arg2: " << argv[argc-1] << endl;
    cout << "Solution: " << reverse(atoi(argv[argc-1])) << endl; 
    return 0;
}




