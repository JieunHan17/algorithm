#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    int cnt = 0;

    scanf("%d %d", &N, &M);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int start = 0, end = 0;
    while (0 <= start && start < N && 0 <= end && end < N)
    {
        int total = 0;
        for (int i = start; i <= end; i++)
        {
            total += A[i];
        }
        if (total == M)
        {
            end++;
            cnt++;
        }
        else if (total < M)
        {
            end++;
        }
        else if (total > M)
        {
            start++;
        }
    }

    printf("%d", cnt);
}