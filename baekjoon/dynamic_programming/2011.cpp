#include <iostream>
#include <string>

#define MAX 5001

using namespace std;

long long dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string code;
    cin >> code;

    dp[0] = 1;
    if (code[0] == '0')
    {
        cout << '0';
        return 0;
    }
    else
    {
        dp[1] = 1;
    }

    for (int i = 2; i <= code.length(); i++)
    {
        int temp = stoi(code.substr(i - 2, 2));
        if (code[i - 1] == '0')
        {
            if (temp > 26 || temp == 0)
            {
                cout << '0';
                return 0;
            }
            dp[i] = dp[i - 2];
        }
        else if (code[i - 2] == '0' || temp > 26)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
        }
    }
    cout << dp[code.length()];
    return 0;
}