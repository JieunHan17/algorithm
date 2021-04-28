#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int N, S;

    scanf("%d %d", &N, &S);

    int a[100000] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    int start = 0, end = 0;
    int answer = 100001;
    int total = a[0];
    while (start <= end && end < N)
    {
        if (total < S)
            total += a[++end];

        else if (total == S)
        {
            answer = min(answer, (end - start + 1));
            total += a[++end];
        }
        else if (total > S)
        {
            answer = min(answer, (end - start + 1));
            total -= a[start++];
        }
    }

    if (answer == 100001)
    {
        printf("%d", 0);
    }
    else
    {
        printf("%d", answer);
    }

    return 0;
}