#include <cstdio>

#define MAX_N 15

using namespace std;

int N;
int board[MAX_N][MAX_N];
bool isUsed1[MAX_N]; // x좌표
bool isUsed2[MAX_N * 2]; // 우상향 대각선 
bool isUsed3[MAX_N * 2]; // 좌하향 대각선
int cnt = 0;

void func(int K)
{
    if (K == N)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!isUsed1[i] && !isUsed2[K + i] && !isUsed3[K - i + N - 1])
        {
            isUsed1[i] = true;
            isUsed2[K + i] = true;
            isUsed3[K - i + N - 1] = true;
            func(K + 1);
            isUsed1[i] = false;
            isUsed2[K + i] = false;
            isUsed3[K - i + N - 1] = false;
        }
    }

}

int main()
{
    scanf("%d", &N);
    func(0);
    printf("%d", cnt);
    return 0;
}