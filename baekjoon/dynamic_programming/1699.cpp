#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX_N 100001

using namespace std;

int dp[MAX_N];

int main()
{
    int N;
    scanf("%d", &N);

    int num = 1;
    while (num * num <= N)
    {
        dp[num * num] = 1;
        num++;
    }

    for (int i = 2; i <= N; i++)
    {
        int temp = sqrt(double(i));
        dp[i] = dp[temp * temp] + dp[i - temp * temp];
        for (int j = temp - 1; j > 0; j--)
        {
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }

    printf("%d", dp[N]);
    return 0;
}