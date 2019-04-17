#include "LongestCommonPrefix.hpp"

LongestCommonPrefix::LongestCommonPrefix()
{
}

LongestCommonPrefix::~LongestCommonPrefix()
{
}

LongestCommonPrefix::LongestCommonPrefix(LongestCommonPrefix &obj)
{
}

LongestCommonPrefix& LongestCommonPrefix::operator=(LongestCommonPrefix &obj)
{
    return *this;
}

string LongestCommonPrefix::getLongestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 0) {return "";}
    string sTemp = strs.at(0);
    string sRetVal("");
    int iStrlength = 0;
    for(vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
    {
        if(it == strs.begin()) {continue;} 
        if(sTemp.compare(*it) == 0)
        {
            sRetVal = sTemp;
        }
        else
        {
            sRetVal = "";
            if(it->length() <= sTemp.length())
            {
                iStrlength = it->length();
            }
            else
            {
                iStrlength = sTemp.length();
            }
            
            for(int i = 0; i < iStrlength; i++)
            {
                if(sTemp.at(i) == it->at(i))
                {
                    sRetVal += sTemp.at(i);
                }
                else
                {
                    break;
                }   
            }
            sTemp = sRetVal;
        } 
    }
    sRetVal = sTemp;
    return sRetVal;
}