#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        unordered_map<string, int> m;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }

        unordered_map<string, int>::iterator idx;
        for (idx = m.begin(); idx != m.end(); idx++)
        {
            cnt *= idx->second + 1;
        }

        cout << cnt - 1 << '\n';
    }

    return 0;
}