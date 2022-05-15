#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string str)
{
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return i;
        }
    }
    return -1;
}

string removeChar(string str, int idx)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (i != idx)
        {
            result += str[i];
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        
        int result = isPalindrome(str);
        if (result == -1)
        {
            cout << '0' << '\n';
            continue;
        }
        else
        {
            if (isPalindrome(removeChar(str, result)) == -1)
            {
                cout << '1' << '\n';
                continue;
            }
            else if (isPalindrome(removeChar(str, str.length() - 1 - result)) == -1)
            {
                cout << '1' << '\n';
                continue;
            }
            else
            {
                cout << '2' << '\n';
                continue;
            }
        }
    }
    return 0;
}