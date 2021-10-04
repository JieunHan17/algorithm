#include <cstdio>

using namespace std;

long long gcd(long long num1, long long num2)
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
    long long A, B, answer;
    scanf("%lld %lld", &A, &B);

    answer = gcd(B, A);

    for (long long i = 0; i < answer; i++)
    {
        printf("1");
    }
    return 0;
}