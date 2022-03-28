#include <cstdio>

using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

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

    for (int i = 1; i <= N; i++)
    {
        if (!isUsed[i])
        {
            arr[K] = i;
            isUsed[i] = true;
            func(K + 1);
            isUsed[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    
    func(0);

    return 0;
}