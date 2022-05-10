#include <cstdio>

#define MAX 2001

using namespace std;

int numbers[MAX];
int dp[MAX][MAX];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 1; i <= N; i++)
    {
        dp[i][i] = 1;
    }
    for (int diff = 1; diff < N; diff++)
    {
        for (int i = 1; i + diff <= N; i++)
        {
            if (numbers[i] == numbers[i + diff])
            {
                if (diff == 1)
                {
                    dp[i][i + diff] = 1;
                }
                else
                {
                    dp[i][i + diff] = dp[i + 1][i + diff - 1];
                }
            }
        }
    }

    int M;
    scanf("%d", &M);
    while (M--)
    {
        int S, E;
        scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }
    return 0;
}