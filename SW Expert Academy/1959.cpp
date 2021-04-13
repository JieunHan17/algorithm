#include <stdio.h>

int N, M;
float A[21] = {
    0},
      B[21] = {0};

float solution(int N, int M)
{
    float max = 0.0;
    float sum = 0.0;
    bool flag = true;
    int limit;

    if (N > M)
    {
        flag = true;
        limit = N;
    }
    else
    {
        flag = false;
        limit = M;
    }

    int diff = flag == true ? (N - M) : (M - N);

    if (flag == true)
    {
        for (int i = 0; i <= diff; i++)
        {
            for (int j = 0; j < limit; j++)
            {
                sum += A[i + j] * B[j];
            }
            if (sum >= max)
            {
                max = sum;
            }
            sum = 0.0;
        }
    }
    else
    {
        for (int i = 0; i <= diff; i++)
        {
            for (int j = 0; j < limit; j++)
            {
                sum += A[j] * B[i + j];
            }
            if (sum >= max)
            {
                max = sum;
            }
            sum = 0.0;
        }
    }

    return max;
}

int main()
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);

        for (int j = 0; j < N; j++)
        {
            scanf("%f", &A[j]);
        }
        for (int j = 0; j < M; j++)
        {
            scanf("%f", &B[j]);
        }

        printf("#%d %.f\n", (i + 1), solution(N, M));

        for (int j = 0; j < N; j++)
        {
            A[j] = 0.0;
        }
        for (int j = 0; j < M; j++)
        {
            B[j] = 0.0;
        }
    }
    return 0;
}