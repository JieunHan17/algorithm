#include <cstdio>

#define MAX 1001

using namespace std;

int dp[MAX];

int main()
{
    int N;
    scanf("%d", &N);

    dp[N] = 1;
    for (int i = N; i > 1; i--)
    {
        if (i - 1 >= 0)
        {
            dp[i - 1] = dp[i] == 1 ? 2 : 1;
        }
        if (i - 3 >= 0)
        {
            dp[i - 3] = dp[i] == 1 ? 2 : 1;
        }
    }

    if (dp[1] == 1)
    {
        printf("SK");
    }
    else if (dp[1] == 2)
    {
        printf("CY");
    }
    return 0;
}