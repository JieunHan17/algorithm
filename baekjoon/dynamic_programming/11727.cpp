#include <stdio.h>
#include <iostream>

using namespace std;

int dp(int n)
{
    int d[1001] = {
        0,
    };

    d[1] = 1;
    d[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] + 2 * d[i - 2];
    }

    return d[n] % 10007;
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d", dp(n));

    return 0;
}