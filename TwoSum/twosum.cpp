#include "twosum.hpp"

int main()
{
    vector<int> ary;
    int target = 0,x = 0;
    cout << "Input array" << endl;
    while(cin >> x && !cin.ignore())
    {
        ary.push_back(x);
    }
    cout << "Input Target" << endl;
    cin >> target;
    for(int i = 0; i < ary.size(); i++)
    {
        for(int j = 0; j < ary.size(); j++)
        {
            if((ary[i] + ary[j]) == target )
            {
                cout << i + ", "+ j << endl;
                return 0;
            }
            else
            {
                cout << "nope!!";
                return 0;
            }
        }
    }
    return 0;
}
