#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int B, C;
    scanf("%d %d", &B, &C);

    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= B)
        {
            cnt += 1;
        }
        else
        {
            cnt += 1;
            cnt += ceil((A[i] - B) / (double)C);
        }
    }

    printf("%lld\n", cnt);
    return 0;
}