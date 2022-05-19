#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX 301

using namespace std;

long long dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 1; i <= N; i++)
    {
        dp[i][1] = dp[i - 1][1] + abs(str1[i - 1] - str2[0]);
    }
    for (int j = 1; j <= M; j++)
    {
        dp[1][j] = dp[1][j - 1] + abs(str1[0] - str2[j - 1]);
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= M; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + abs(str1[i - 1] - str2[j - 1]);
            }
        }
    }

    cout << dp[N][M];
    return 0;
}