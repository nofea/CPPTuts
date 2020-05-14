/* Find the next palindrome from a given number n
100 <= n <= 1000

Eg: Input n = 134
next palindrome is 141 
condition: cannot use arrays of any kind*/

#include <iostream>
#include <math.h>
using namespace std;

int getNextPalindrome(const int& n)
{
    int iPalin = 0, iFirstDigit = 0, iSecondDigit = 0;

    if (n == 1000)
    {
        iPalin = 1001;
    }
    else
    {
        iFirstDigit = floor(n/100);
        iPalin = floor(n / 10);
        iPalin *= 10;
        iPalin += iFirstDigit;

        if(iPalin <= n)
        {
            iSecondDigit = floor(iPalin/10);
            iSecondDigit = iSecondDigit % 10;
            iSecondDigit++;

            iPalin = iFirstDigit * 100 + iSecondDigit * 10 + iFirstDigit;
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