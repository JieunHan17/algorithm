#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    stack<char> s;
    int temp = 1;
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
            temp *= 2;
        }
        else if (str[i] == '[')
        {
            s.push(str[i]);
            temp *= 3;
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(')
                ans += temp;
            s.pop();
            temp /= 2;
        }
        else
        {
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[')
                ans += temp;
            s.pop();
            temp /= 3;
        }
    }

    if (!s.empty())
    {
        cout << '0';
        return 0;
    }

    cout << ans;
    return 0;
}