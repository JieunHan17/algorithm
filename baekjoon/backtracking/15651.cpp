#include <cstdio>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int arr[MAX];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        arr[i] = 0;
    }
    for (int i = M; i < N; i++)
    {
        arr[i] = 1;
    }

    do
    {
        for (int i = 0; i < N; i++)
        {
            if (!arr[i])
            {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    } while (next_permutation(arr, arr + N));
    
    return 0;
}