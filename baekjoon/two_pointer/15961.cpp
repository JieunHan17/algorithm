#include <cstdio>
#include <algorithm>

#define MAX 3001

using namespace std;

int main()
{
    int N, d, k, c;

    scanf("%d %d %d %d", &N, &d, &k, &c);

    int dishes[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &dishes[i]);
    }

    int dishes_cnt = 1;
    int sushi_cnt = 1;
    int start = 0, end = 0;
    int check[MAX] = {
        0,
    };
    bool isThereCoupon = false;

    check[dishes[0]] = 1;
    if (dishes[0] == c)
    {
        isThereCoupon = true;
    }

    int maximum = sushi_cnt;
    while (start < N - 1)
    {
        if (dishes_cnt <= k)
        {
            if (dishes_cnt == k)
            {
                if (isThereCoupon)
                {
                    maximum = max(maximum, sushi_cnt);
                }
                else
                {
                    maximum = max(maximum, sushi_cnt + 1);
                }
            }

            maximum = max(maximum, sushi_cnt);

            end++;
            if (end == N)
            {
                end = 0;
            }

            check[dishes[end]]++;
            if (check[dishes[end]] == 1)
            {
                sushi_cnt++;
            }

            if (dishes[end] == c)
            {
                isThereCoupon = true;
            }

            dishes_cnt++;
        }

        else
        {
            check[dishes[start]]--;
            if (check[dishes[start]] == 0)
            {
                sushi_cnt--;
                if (dishes[start] == c)
                {
                    isThereCoupon = false;
                }
            }

            start++;
            dishes_cnt--;
        }
    }

    printf("%d\n", maximum);

    return 0;
}