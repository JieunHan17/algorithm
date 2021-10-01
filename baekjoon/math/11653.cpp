#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 10000001

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<bool> prime(MAX, true);
    prime[0] = false;

    long long cnt = 0;
    for (int i = 2; i < MAX; i++)
    {
        for (int j = 2; i * j < MAX; j++)
        {
            prime[i * j] = false;
            cnt++;
        }
    }

    int divider = 2;
    while (N > 1)
    {
        if (prime[divider])
        {
            if (N % divider == 0)
            {
                N /= divider;
                printf("%d\n", divider);
            }
            else
            {
                divider++;
            }
        }
        else
        {
            divider++;
        }
    }
    return 0;
}

//그냥 나눠지면 인수를 출력하면 된다.