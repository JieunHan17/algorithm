#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

map<string, double> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout.precision(4);

    int total = 0;
    while (1)
    {
        string str = "";
        getline(cin, str);
        if (str == "")
        {
            break;
        }
        m[str]++;
        total++;
    }

    for (map<string, double>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " " << iter->second / total * 100.0 << '\n';
    }
    return 0;
}