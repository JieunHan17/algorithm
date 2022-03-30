#include <cstdio>

#define MAX 9

using namespace std;

int N, M;
int arr[MAX];

void func(int K)
{
    if (K == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    int start = K == 0? 1 : arr[K - 1];
    for (int i = start; i <= N; i++)
    {
        arr[K] = i;
        func(K + 1);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    func(0);
    return 0;
}