/* 틀렸습니다 */
#include <cstdio>
#include <algorithm>

#define MAX 101
#define MAX_COST 10001
#define INF 987654321

using namespace std;

int memory[MAX] = {
    0,
};
int cost[MAX] = {
    0,
};
int dp[MAX][MAX_COST] = {
    0,
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &memory[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &cost[i]);
    }

    int ans = INF;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < MAX_COST; j++)
        {
            if (cost[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], memory[i] + dp[i - 1][j - cost[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

            if (dp[i][j] >= M)
            {
                ans = min(ans, j);
            }
        }
    }

    printf("%d", ans);

    return 0;
}