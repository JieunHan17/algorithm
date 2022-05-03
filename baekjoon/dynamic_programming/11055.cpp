#include <cstdio>
#include <algorithm>

#define MAX_N 1001

using namespace std;

int A[MAX_N];
int dp[MAX_N];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
        dp[i] = A[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }

    printf("%d", *max_element(dp, dp + N + 1));
    return 0;
}