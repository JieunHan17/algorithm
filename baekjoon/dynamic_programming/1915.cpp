#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

int board[MAX][MAX];
int dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = input[j] - '0';
            if (board[i][j] == 1)
            {
                dp[i][j] = 1;
            }
        }
    }

    int side = 2;
    while (side <= m && side <= n)
    {
        for (int i = 0; i <= n - side; i++)
        {
            for (int j = 0; j <= m - side; j++)
            {
                if (dp[i][j] == side - 1 && dp[i][j + 1] == side - 1 && dp[i + 1][j] == side - 1 && dp[i + 1][j + 1] == side - 1)
                {
                    dp[i][j] = side;
                }
            }
        }
        side++;
    }

    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maximum = max(maximum, dp[i][j]);
        }
    }
    cout << maximum * maximum;
    return 0;
}