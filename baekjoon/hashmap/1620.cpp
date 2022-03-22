#include <iostream>
#include <unordered_map>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> m;
    string idx[N + 1];
    for (int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;
        m[name] = i;
        idx[i] = name;
    }

    while (M--)
    {
        string input;
        cin >> input;
        if (isdigit(input[0]))
        {
            cout << idx[stoi(input)] << '\n';
        }
        else
        {
            cout << m[input] << '\n';
        }
    }
    return 0;
}