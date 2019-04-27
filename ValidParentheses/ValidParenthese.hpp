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
    bool bRetVal = false;
    return bRetVal;
}