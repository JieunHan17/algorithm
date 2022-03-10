#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin.ignore();

    while (1)
    {
        string s;
        getline(cin, s);
        if (s == ".")
        {
            break;
        }

        bool isWrong = false;
        stack<char> braces;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                braces.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (braces.empty())
                {
                    isWrong = true;
                    break;
                }
                else if (braces.top() != '(')
                {
                    isWrong = true;
                    break;
                }
                else
                {
                    braces.pop();
                }
            }
            else if (s[i] == ']')
            {
                if (braces.empty())
                {
                    isWrong = true;
                    break;
                }
                else if (braces.top() != '[')
                {
                    isWrong = true;
                    break;
                }
                else
                {
                    braces.pop();
                }
            }
        }

        if (!braces.empty())
        {
            isWrong = true;
        }

        if (isWrong)
        {
            cout << "no" << '\n';
        }
        else
        {
            cout << "yes" << '\n';
        }
    }

    return 0;
}