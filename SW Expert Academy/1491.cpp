#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long N = 0, A = 0, B = 0;

long solution()
{
    long R = sqrt(N);
    long C = sqrt(N);
    long min = A * labs(R - C) + B * (N - R * C);
    long temp = 0;

    C += 1;

    while (R > 1)
    {
        while (N >= R * C)
        {
            temp = A * labs(R - C) + B * (N - R * C);

            if (temp < min && temp > 0)
            {
                min = temp;
            }

            C += 1;
        }
        R -= 1;
    }

    return min;
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%ld %ld %ld", &N, &A, &B);
        printf("#%d %ld\n", (i + 1), solution());
    }
    return 0;
}