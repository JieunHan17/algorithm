#include <cstdio>

#define MAX_N 91

using namespace std;

long long dp[MAX_N][2];

int main()
{
    int N;
    scanf("%d", &N);

    dp[1][1] = 1;
    dp[2][0] = 1;
    for (int i = 3; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    printf("%lld", dp[N][0] + dp[N][1]);
    return 0;
}