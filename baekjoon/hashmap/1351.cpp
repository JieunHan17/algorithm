#include <cstdio>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> m;

long long dp(long long num)
{
    if (m.find(num) != m.end())
    {
        return m[num];
    }
    else
    {
        return m[num] = dp(num/P) + dp(num/Q);
    }
}

int main()
{
    scanf("%lld %lld %lld", &N, &P, &Q);
    m[0] = 1;
    printf("%lld", dp(N));

    return 0;
}