#include <cstdio>

#define MAX_N 21

using namespace std;

int N, S;
int cnt = 0;
int numbers[MAX_N];

void func(int K, int total)
{
    if (K == N)
    {
        if (total == S)
        {
            cnt++;
        }
        return;
    }

    func(K + 1, total);
    func(K + 1, total + numbers[K]);
}

int main()
{
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }
    func(0, 0);
    if (S == 0)
    {
        cnt--; // 공집합 제외
    }
    printf("%d", cnt);
    return 0;
}