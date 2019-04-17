#include <iostream>
#include <vector>

using namespace std;

class LongestCommonPrefix
{
    public:
    LongestCommonPrefix();
    ~LongestCommonPrefix();
    LongestCommonPrefix(LongestCommonPrefix &obj);
    LongestCommonPrefix& operator= (LongestCommonPrefix &obj);

    //main function
    string getLongestCommonPrefix(vector<string>& strs);
};