#include <cstdio>

using namespace std;

int main()
{
    int sum = 64;
    int minimum = 64;
    int cnt = 1;
    int X;
    scanf("%d", &X);

    while (sum > X)
    {
        sum -= minimum;
        cnt--;
        if (sum + (minimum >> 1) >= X)
        {
            cnt += 1;
            sum += (minimum >> 1);
        }
        else
        {
            cnt += 2;
            sum += minimum;
        }
        minimum = (minimum >> 1);
    }

    printf("%d\n", cnt);
    return 0;
}

/* The simpler way */
/*
int main()
{
    printf("*%d\n", 1 >> 1);
    int X;
    scanf("%d", &X);

    int cnt = 0;
    while (X >= 1)
    {
        cnt += X % 2;
        X /= 2;
    }
    printf("%d\n", cnt);
    return 0;
}
*/
