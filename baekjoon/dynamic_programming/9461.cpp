#include <cstdio>

#define MAX_N 101

using namespace std;

long long dp[MAX_N];

int main()
{
    int T;
    scanf("%d", &T);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    
    while (T--)
    {
        int N;
        scanf("%d", &N);

        if (dp[N] == 0)
        {
            for (int i = 6; i <= N; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 5];
            }
        }
        
        printf("%lld\n", dp[N]);
    }
    return 0;
}