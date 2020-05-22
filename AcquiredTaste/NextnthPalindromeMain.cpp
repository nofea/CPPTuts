//do not use arrays of any kind 

/* find the nth Palindrome from any given number k
Eg: 

Input: n = 3
          k = 122

Output : 151 */

#include <iostream>
#include <math.h>
using namespace std;

int getNumberOfDigits(int k)
{
    int iNum = 0;

    while(k > 0)
    {
        k /= 10;
        iNum++;
    }
    return(iNum);
}

int reverseNumber(int k)
{
    int iReverseNum = 0, iDigit = 0;

    while(k > 0)
    {
        iDigit = k % 10;
        iReverseNum = iReverseNum * 10 + iDigit;
        k /= 10;
    }

    return(iReverseNum);
}

int getNextPalindrome(const int& k, const int& n)
{
    int iPalin = 0, iDigit = 0, iNumOfDigits = 0, iMidDigit = 0, iHalfNumFactor = 0, iTempNum = 0;
   
    iNumOfDigits = getNumberOfDigits(k);

    if(iNumOfDigits == 1)
    {
        
    }
    else
    {
        
    }
    
    iTempNum = k;
    iHalfNumFactor = pow(10, floor(iNumOfDigits/2));

    iDigit = floor(k / iHalfNumFactor);
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
    
    
    if(iPalin <= k)
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
    
    
    return(iPalin);
}

int main()
{
    int k, n;
    cout << "Enter a number, k..." << endl;
    cin >> k;

    cout << "Enter a number, n..." << endl;
    cin >> n;
    cout << getNextPalindrome(k, n) << endl;

    return 0;
}