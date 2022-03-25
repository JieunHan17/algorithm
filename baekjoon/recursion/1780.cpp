#include <cstdio>
#define MAX_N 2188

using namespace std;

int cntMinusOne, cntZero, cntOne;
int paper[MAX_N][MAX_N];

bool findDifferent(int N, int startY, int startX)
{
    int init = paper[startY][startX];
    for (int i = startY; i < startY + N; i++)
    {
        for (int j = startX; j < startX + N; j++)
        {
            if (paper[i][j] != init)
            {
                return true;
            }
        }
    }
    return false;
}

void recur(int N, int startY, int startX)
{
    if (N == 1)
    {
        if (paper[startY][startX] == -1)
        {
            cntMinusOne++;
        }
        else if (paper[startY][startX] == 0)
        {
            cntZero++;
        }
        else
        {
            cntOne++;
        }
        return;
    }

    bool isDifferent = findDifferent(N, startY, startX);

    if (isDifferent)
    {
        int num = N / 3;
        recur(num, startY, startX);
        recur(num, startY, startX + num);
        recur(num, startY, startX + num * 2);
        recur(num, startY + num, startX);
        recur(num, startY + num, startX + num);
        recur(num, startY + num, startX + num * 2);
        recur(num, startY + num * 2, startX);
        recur(num, startY + num * 2, startX + num);
        recur(num, startY + num * 2, startX + num * 2);
    }   
    else
    {
        if (paper[startY][startX] == -1)
            cntMinusOne++;
        else if (paper[startY][startX] == 0)
            cntZero++;
        else
            cntOne++;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }
    recur(N, 0, 0);
    printf("%d\n", cntMinusOne);
    printf("%d\n", cntZero);
    printf("%d\n", cntOne);
    return 0;
}