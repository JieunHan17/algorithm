#include <stdio.h>

int n;
int d[11];

int solution(int n)
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    return d[n];
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        printf("%d\n", solution(n));
    }

    return 0;
}