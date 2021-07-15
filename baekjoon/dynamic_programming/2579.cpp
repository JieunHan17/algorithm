#include <cstdio>
#include <algorithm>
#define MAX 301

using namespace std;

int main()
{
    int stairsNum;
    int stairs[MAX];
    int dp[MAX][2] = {
        0,
    };

    scanf("%d", &stairsNum);
    for (int i = 1; i <= stairsNum; i++)
    {
        scanf("%d", &stairs[i]);
    }

    dp[1][0] = dp[1][1] = stairs[1];
    for (int i = 2; i <= stairsNum; i++)
    {
        dp[i][0] = dp[i - 1][1] + stairs[i];
        dp[i][1] = max(dp[i - 2][0] + stairs[i], dp[i - 2][1] + stairs[i]);
    }

    printf("%d", max(dp[stairsNum][0], dp[stairsNum][1]));

    return 0;
}