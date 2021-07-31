#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }

    sort(array, array + N);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}