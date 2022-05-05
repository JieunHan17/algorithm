#include <cstdio>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    long long dp[10][N + 1];

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            dp[i][1] = 0;
        }
        else
        {
            dp[i][1] = 1;
        }
    }

    //( a + b ) % c = ( a % c + b % c ) % c
    for (int j = 2; j <= N; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == 0)
            {
                dp[i][j] = dp[i + 1][j - 1] % 1000000000;
            }
            else if (i == 9)
            {
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            }
            else
            {
                dp[i][j] = (dp[i + 1][j - 1] + dp[i - 1][j - 1]) % 1000000000;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += dp[i][N];
    }

    printf("%lld", ans % 1000000000);
    return 0;
}