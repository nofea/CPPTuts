#include <iostream>
#include <vector>
using namespace std;
string SingleSpace = " ";

void printMat(vector<vector<int>>& iMat)
{
    for(vector<vector<int>>::iterator i = iMat.begin(); i != iMat.end(); ++i)
    {
        for(vector<int>:: iterator j = i->begin(); j != i->end(); ++j)
        {
            cout << *j << SingleSpace;
        }
        cout << endl;
    }
}

void printVec(vector<int> &iVec)
{
    for (vector<int>::iterator j = iVec.begin(); j != iVec.end(); ++j)
    {
        cout << *j << SingleSpace;
    }
}

void solution(int& x, int& y, vector<vector<int>>& iMat, vector<int>& iSolution)
{
    vector<int> row, col;
    int m = 0, n = 0;

    for(int i = 0; i < x; i++)
    {
        row.push_back(i);
    }
    for (int j = 0; j < y; j++)
    {
        col.push_back(j);
    }

    while(row.size() != 0 && col.size() != 0)
    {
        m = 0;
        n = 0;
        while(n < col.size())
        {
            iSolution.push_back(iMat.at(row.at(m)).at(col.at(n)));
            n++;
        }
        n--;
        row.erase(row.begin() + m);

        while(m < row.size())
        {
            iSolution.push_back(iMat.at(row.at(m)).at(col.at(n)));
            m++;
        }
        m--;
        col.erase(col.begin() + n);

        while(n >= 0)
        {
            iSolution.push_back(iMat.at(row.at(m)).at(col.at(n)));
            n--;
        }
        n++;
        row.erase(row.begin() + m);
        while(m >= 0)
        {
            iSolution.push_back(iMat.at(row.at(m)).at(col.at(n)));
            m--;
        }
        m++;
        col.erase(col.begin() + n);
    }
}

int main()
{
    int x, y, temp;
    cin >> x >> y;

    vector<vector<int>> iMat;
    vector<int> iSolution;
    iMat.resize(x);

    for(int i = 0; i < x; i++)
    {
        iMat.at(i).resize(y);
        for(int j = 0; j < y; j++)
        {
            cin >> iMat.at(i).at(j);
        }
    }
    
    cout << "The Input matrix is" << endl;
    printMat(iMat);

    solution(x, y, iMat, iSolution);
    cout << "The Snake..." << endl;
    printVec(iSolution);
    
    return 0;
}