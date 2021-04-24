#include <stdio.h>
#include <iostream>

using namespace std;

int dp(int N)
{
    int d[31] = {
        0,
    };

    d[0] = 1;
    d[2] = 3;

    for (int i = 4; i <= N; i++)
    {
        d[i] = 3 * d[i - 2];
        for (int j = 4; j <= i; j += 2)
        {
            d[i] += 2 * d[i - j];
        }
    }

    return d[N];
}

int main()
{
    int N;

    scanf("%d", &N);
    printf("%d", dp(N));

    return 0;
}