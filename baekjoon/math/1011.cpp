#include <cstdio>
#include <cmath>

using namespace std;

long long cal(long long dist)
{
    long long max_speed = sqrt(dist);
    long long cnt = 2 * max_speed - 1;
    cnt += ceil((dist - pow(max_speed, 2)) / max_speed);
    return cnt;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        printf("%lld\n", cal(y - x));
    }
    return 0;
}