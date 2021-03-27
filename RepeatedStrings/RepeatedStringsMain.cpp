#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    
    long lNumOfAs = 0;
    int iPosition = 0;
    unsigned long lPossibleExtras = 0;
    unsigned long lStringLength = s.size();
    vector<int> vecCharPositions;
    unsigned long lExtras = 0;

    unsigned long lCount = count(s.begin(), s.end(), 'a');

    if(lCount != 0)
    {
        double fReoccuranceFactor = static_cast<double>(n) / static_cast<double>(lStringLength);
    
        double FactorFraction = fReoccuranceFactor - static_cast<double>(static_cast<long>(fReoccuranceFactor));
        
        if(FactorFraction != 0.0)
        {   
            iPosition = s.find('a');
            vecCharPositions.push_back(iPosition);
            for(unsigned int i = 1; i < lCount; i++)
            {
                iPosition = s.find('a', iPosition + 1);
                vecCharPositions.push_back(iPosition);
            }
            
            lPossibleExtras = round(FactorFraction * lCount);
            
            for(auto it = vecCharPositions.begin(); it != vecCharPositions.end(); ++it)
            {
                if(*it <= (lPossibleExtras - 1))
                {
                    lExtras++;
                }
            }
        }
        
        lNumOfAs = lCount * static_cast<long>(fReoccuranceFactor) + lExtras; 
    }
    
    return  lNumOfAs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);
    cout << result << endl;

    fout << result << "\n";

    fout.close();

    return 0;
}
