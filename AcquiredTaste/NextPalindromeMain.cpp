//do not use arrays of any kind 

#include <iostream>
#include <math.h>
using namespace std;

int getNumberOfDigits(int n)
{
    int iNum = 0;

    while(n > 0)
    {
        n /= 10;
        iNum++;
    }
    return(iNum);
}

int reverseNumber(int n)
{
    int iReverseNum = 0, iDigit = 0;

    while(n > 0)
    {
        iDigit = n % 10;
        iReverseNum = iReverseNum * 10 + iDigit;
        n /= 10;
    }

    return(iReverseNum);
}

int getNextPalindrome(const int& n)
{
    int iPalin = 0, iDigit = 0, iNumOfDigits = 0, iMidDigit = 0, iHalfNumFactor = 0, iTempNum = 0;

    if(n < 9)
    {
        iPalin = n + 1;
    }
    else if(n == 9)
    {
        iPalin = 11;
    }
    else
    {
        iNumOfDigits = getNumberOfDigits(n);
        iTempNum = n;
        iHalfNumFactor = pow(10, floor(iNumOfDigits/2));

        iDigit = floor(n / iHalfNumFactor);
        iPalin = iDigit;
        iPalin *= iHalfNumFactor;

        if(iNumOfDigits % 2 == 0)
        {
            iPalin += reverseNumber(iDigit);
        }
        else
        {
            iPalin += reverseNumber(floor(iDigit/10));
        }
        
        
        if(iPalin <= n)
        {
            iMidDigit = iDigit % 10;
            iDigit /= 10;
            iDigit *= 10;
            iDigit += iMidDigit + 1;
            iPalin = iDigit;
            iPalin *= iHalfNumFactor;
            if(iNumOfDigits % 2 == 0)
            {
                iPalin += reverseNumber(iDigit);
            }
            else
            {
                iPalin += reverseNumber(floor(iDigit/10));
            }   
        }
    }
    
    return(iPalin);
}

int main()
{
    int n;
    cout << "Enter a number..." << endl;
    cin >> n;

    cout << getNextPalindrome(n) << endl;
    return 0;
}