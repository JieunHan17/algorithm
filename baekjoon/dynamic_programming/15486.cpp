#include <cstdio>
#include <utility>
#include <algorithm>

#define MAX_N 1500002

using namespace std;

int dp[MAX_N];
pair<int, int> schedule[MAX_N];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int T, P;
        scanf("%d %d", &T, &P);
        schedule[i].first = T;
        schedule[i].second = P;
    }
    
    for (int i = N; i >= 1; i--)
    {
        if (i + schedule[i].first - 1 <= N)
        {
            dp[i] = max(dp[i + 1], dp[i + schedule[i].first] + schedule[i].second);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", dp[i]);
    }
    
    printf("%d", *max_element(dp + 1, dp + N + 1));
    return 0;
}