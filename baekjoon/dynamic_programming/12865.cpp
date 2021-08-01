/* 시간 초과 */
//2차원 DP로 해야할듯
#include <cstdio>
#include <algorithm>

#define MAX_OBJECT 101
#define MAX 100001

using namespace std;

int dp[MAX_OBJECT][MAX] = {
    0,
};
int object[2][MAX_OBJECT] = {
    0,
};

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
    {
        int W, V;
        scanf("%d %d", &W, &V);
        object[0][i] = W;
        object[1][i] = V;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (object[0][i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], object[1][i] + dp[i - 1][j - object[0][i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("%d", dp[N][K]);
    return 0;
}