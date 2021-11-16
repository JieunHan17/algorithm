#include <cstdio>
#include <algorithm>

#define MAX 500001

using namespace std;

int array1[MAX];
int array2[MAX];

int main()
{
    int N, M;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array1[i]);
    }

    sort(array1, array1 + N);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &array2[i]);
    }

    for (int i = 0; i < M; i++)
    {
        printf("%ld ", upper_bound(array1, array1 + N, array2[i]) - lower_bound(array1, array1 + N, array2[i]));
    }
    return 0;
}