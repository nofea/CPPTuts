#ifndef ROMANNUMERALDICTIONARY_H
#define ROMANNUMERALDICTIONARY_H

#include <string>
#include <map>

using namespace std;

class RomanNumeralDictionary
{
private:
    map<char,int> RND;
public:
    RomanNumeralDictionary(/* args */);
    ~RomanNumeralDictionary();
    RomanNumeralDictionary(RomanNumeralDictionary &obj);
    RomanNumeralDictionary& operator= (RomanNumeralDictionary &obj);

    //getters
    int getInteger(string sRomanNumeral);
};

RomanNumeralDictionary::RomanNumeralDictionary()
{
    RND.insert(pair<char,int>('I', 1));
    RND.insert(pair<char,int>('V', 5));
    RND.insert(pair<char,int>('X', 10));
    RND.insert(pair<char,int>('L', 50));
    RND.insert(pair<char,int>('C', 100));
    RND.insert(pair<char,int>('D', 500));
    RND.insert(pair<char,int>('M', 1000));
}

RomanNumeralDictionary::~RomanNumeralDictionary()
{
}

RomanNumeralDictionary::RomanNumeralDictionary(RomanNumeralDictionary &obj)
{
}

RomanNumeralDictionary& RomanNumeralDictionary::operator= (RomanNumeralDictionary &obj)
{
    return *this;
}

int RomanNumeralDictionary::getInteger(string sRomanNumeral)
{
    int iInteger = 0;
    if(sRomanNumeral.length() == 1)
    {
        char cRomanNumeral[1] = {*sRomanNumeral.c_str()};
        iInteger = RND.find(cRomanNumeral[0])->second;
    }
    else if(sRomanNumeral.length() > 1)
    {
        int iCount = 0, iTemp = 0, iTempPrev;
        while(iCount < sRomanNumeral.length())
        {
            iTemp = RND.find(sRomanNumeral.at(iCount))->second;
            if(iTemp == -1) {return -1;}
            if((iCount != 0) && (iTempPrev == iTemp))
            {   
                iInteger += iTemp;
            }
            else if((iCount != 0) && (iTemp == 5) && (iTempPrev == 1))
            {
                iInteger += 4 - 1;
            }
            else if((iCount != 0) && (iTemp == 10) && (iTempPrev == 1))
            {
                iInteger += 9 - 1;
            }
            else if((iCount != 0) && (iTemp == 50) && (iTempPrev == 10))
            {
                iInteger += 40 - 10;
            }
            else if((iCount != 0) && (iTemp == 100) && (iTempPrev == 10))
            {
                iInteger += 90 - 10;
            }
            else if((iCount != 0) && (iTemp == 500) && (iTempPrev == 100))
            {
                iInteger += 400 - 100;
            }
            else if((iCount != 0) && (iTemp == 1000) && (iTempPrev == 100))
            {
                iInteger += 900 - 100;
            }
            else
            {
                iInteger += iTemp;
            }
            
            iTempPrev = RND.find(sRomanNumeral.at(iCount))->second;
            iCount++;
        }
    }
    else
    {
        iInteger = -1;
    }
    
    return iInteger;
}


#endif