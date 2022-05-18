#include <iostream>
#include <string>
#include <vector>

#define MAX 1000001

using namespace std;

vector<int> makeTable(string pattern)
{
    int patternSize = pattern.length();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern)
{
    vector<int> table = makeTable(pattern);
    int parentSize = parent.length();
    int patternSize = pattern.length();
    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                j = table[j];
                cout << 1;
                return;
            }
            else
            {
                j++;
            }
        }
    }
    cout << 0;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S, P;
    cin >> S >> P;
    
    KMP(S, P);
    
    return 0;
}