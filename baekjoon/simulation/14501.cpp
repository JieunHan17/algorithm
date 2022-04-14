#include <cstdio>
#include <algorithm>

#define MAX_N 16

using namespace std;

int N;
int T[MAX_N], P[MAX_N];
int benefit = 0;

void func(int idx, int total)
{
    if (idx + T[idx] - 1 >= N)
    {
        benefit = max(benefit, total);
        return;
    }
    total += P[idx];
    
    int next = idx + T[idx];
    for (int i = next; i < N; i++)
    {
        func(i, total);
    }
    benefit = max(benefit, total);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &T[i], &P[i]);
    }

    for (int i = 0; i < N; i++)
    {
        func(i, 0);
    }

    printf("%d", benefit);
    return 0;
}