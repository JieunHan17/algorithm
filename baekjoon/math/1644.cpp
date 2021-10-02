#include <cstdio>
#include <algorithm>

#define MAX 4000001

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    bool prime[MAX];
    fill(prime, prime + MAX, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        for (int j = 2; i * j <= MAX; j++)
        {
            prime[i * j] = false;
        }
    }

    int left = 2, right = 2;
    int cnt = 0;
    int total = 2;
    bool isRightChanged = false;
    while (left <= right)
    {
        if (!prime[left])
        {
            left++;
            continue;
        }
        if (!prime[right])
        {
            right++;
            continue;
        }
        else
        {
            if (isRightChanged)
            {
                total += right;
            }
        }

        if (total < N)
        {
            right++;
            isRightChanged = true;
        }
        else if (total == N)
        {
            cnt++;
            right++;
            isRightChanged = true;
        }
        else
        {
            if (prime[left])
            {
                total -= left;
            }
            left++;
            isRightChanged = false;
        }
    }

    printf("%d\n", cnt);
    return 0;
}