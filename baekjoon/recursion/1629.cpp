#include <cstdio>

using namespace std;

long long recur(long long A, long long B, long long C)
{
    if (B == 1)
    {
        return A % C;
    }
    long long temp = recur(A, B / 2, C);
    temp = temp * temp % C;
    if (B % 2 == 0)
    {
        return temp;
    }
    else
    {
        return temp * A % C;
    }
}

int main()
{
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld", recur(A, B, C));
    return 0;
}