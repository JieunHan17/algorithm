#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, num1 % num2);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int input[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
    }

    int gcdFromLeft[N];
    gcdFromLeft[0] = input[0];
    for (int i = 1; i < N; i++)
    {
        gcdFromLeft[i] = gcd(gcdFromLeft[i - 1], input[i]);
    }

    int gcdFromRight[N];
    gcdFromRight[N - 1] = input[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        gcdFromRight[i] = gcd(gcdFromRight[i + 1], input[i]);
    }

    int maximum = 0;
    int K = 0;
    for (int i = 0; i < N; i++)
    {
        int newGcd;
        if (i == 0)
        {
            newGcd = gcdFromRight[i + 1];
        }
        else if (i == N - 1)
        {
            newGcd = gcdFromLeft[i - 1];
        }
        else
        {
            newGcd = gcd(gcdFromLeft[i - 1], gcdFromRight[i + 1]);
        }

        if (input[i] % newGcd)
        {
            maximum = max(maximum, newGcd);
            K = input[i];
        }
    }

    if (maximum == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d\n", maximum, K);
    }

    return 0;
}