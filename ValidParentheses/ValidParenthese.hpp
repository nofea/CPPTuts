#include <iostream>
#include <map>

using namespace std;

class ValidParenthese
{
    private:
    map<char,char> mapParenthese;

    public:
    ValidParenthese();
    ~ValidParenthese();
    ValidParenthese(ValidParenthese& obj);
    ValidParenthese& operator=(ValidParenthese& obj);

    //main function
    bool isValid(string s);
};

ValidParenthese::ValidParenthese()
{
    mapParenthese.insert(pair<char,char>('(',')'));
    mapParenthese.insert(pair<char,char>('{','}'));
    mapParenthese.insert(pair<char,char>('[',']'));
}

ValidParenthese::~ValidParenthese()
{

}

ValidParenthese::ValidParenthese(ValidParenthese& obj)
{

}

ValidParenthese& ValidParenthese::operator=(ValidParenthese& obj)
{

}

bool ValidParenthese::isValid(string s)
{
    bool bRetVal = true;
    int iStrLen = s.length();
    if(iStrLen == 0) {return true;}
    int iStrLenHalf = iStrLen/2;
    if(iStrLen % 2 != 0)
    {
        return false;
    }

    if(mapParenthese.find(s.at(0))->second == s.at(1))
    {
        for(int i = 2; i < iStrLen; i++)
        {
            if(mapParenthese.find(s.at(i))->second == s.at(i+1))
            {
                
            }
        }
    }
    else
    {
        for(int i = 0; i < iStrLenHalf; i++)
        {
            if((s.at(i) == mapParenthese.find(s.at(i))->second) && (i = 0))
            {
                break;
            }
            else
            {
                if(mapParenthese.find(s.at(i))->second != s.at(iStrLen - i - 1))
                {
                    bRetVal = false;
                    break;
                }
            }      
        }   
    }
    return bRetVal;
}