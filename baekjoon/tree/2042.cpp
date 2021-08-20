#include <cstdio>

#define MAX 4000001

using namespace std;

long long tree[MAX] = {
    0,
};
int N, M, K;

void update(int node, long long diff)
{
    while (node > 0)
    {
        tree[node] += diff;
        node /= 2;
    }
}

long long getSum(int start, int end)
{
    long long result = 0;
    while (start <= end)
    {
        if (start % 2 == 1)
        {
            result += tree[start];
        }
        if (end % 2 == 0)
        {
            result += tree[end];
        }
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return result;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    //leaf node의 첫 번째 인덱스
    int s = 1;
    while (s < N)
    {
        s *= 2;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &tree[i + s]);
    }

    for (int i = s - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    for (int i = 0; i < M + K; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 1)
        {
            long long c;
            scanf("%lld", &c);
            update(s + b - 1, c - tree[s + b - 1]);
        }
        else
        {
            int c;
            scanf("%d", &c);
            printf("%lld\n", getSum(s + b - 1, s + c - 1));
        }
    }

    return 0;
}