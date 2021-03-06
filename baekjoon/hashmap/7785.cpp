#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

unordered_set<string> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        string name, log;
        cin >> name >> log;
        if (log == "enter")
        {
            s.insert(name);
        }
        else
        {
            s.erase(name);
        }
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for (vector<string>::iterator i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << '\n';
    }

    return 0;
}