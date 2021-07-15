#include <cstdio>

#define MAX 100001

using namespace std;

int main()
{
    int N, M;
    int num[MAX];
    int dp[MAX] = {
        0,
    };

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &num[i]);
    }

    dp[1] = num[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + num[i];
    }

    for (int i = 0; i < M; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", dp[end] - dp[start - 1]);
    }
    return 0;
}