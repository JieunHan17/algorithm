#include <stdio.h>

int num;
int d[41], cntZero[41] = {0}, cntOne[41] = {0};

int dp(int n)
{
    d[0] = 0;
    cntZero[0] = 1;
    d[1] = 1;
    cntOne[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
        cntZero[i] = cntZero[i - 1] + cntZero[i - 2];
        cntOne[i] = cntOne[i - 1] + cntOne[i - 2];
    }

    return d[n];
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &num);
        dp(num);
        printf("%d %d\n", cntZero[num], cntOne[num]);
    }

    return 0;
}