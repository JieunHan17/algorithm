#include <cstdio>
#include <algorithm>

#define MAX 101
#define MAX_K 10001
#define MAX_VALUE 100001

using namespace std;

int values[MAX];
int dp[MAX_K];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    fill(dp, dp + MAX_K, MAX_VALUE);

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = values[i]; j <= k; j++)
        {
            dp[j] = min(dp[j], dp[j - values[i]] + 1);
        }
    }
    
    if (dp[k] == MAX_VALUE)
    {
        printf("-1");
    }
    else
    {
        printf("%d", dp[k]);
    }
    return 0;
}