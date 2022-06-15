#include <cstdio>
#include <algorithm>

#define MAX 100001

using namespace std;

int weights[MAX];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &weights[i]);
    }
    sort(weights, weights + N);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, (N - i) * weights[i]);
    }

    printf("%d", ans);
    return 0;
}