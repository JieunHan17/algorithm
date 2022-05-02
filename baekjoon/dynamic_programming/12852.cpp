#include <cstdio>

#define MAX_N 1000001

using namespace std;

int dp[MAX_N];
int pre[MAX_N];

int main()
{
    int N;
    scanf("%d" , &N);

    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
        {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
    }

    printf("%d\n", dp[N]);
    int cur = N;
    while (1)
    {
        printf("%d ", cur);
        if (cur == 1)
        {
            break;
        }
        cur = pre[cur];
    }
    return 0;
}