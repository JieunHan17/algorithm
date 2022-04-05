// 시간 복잡도 = 100 * 4 * (10 * 10) * (40 * 40) = 64,000,000

#include <cstdio>

#define MAX 41
#define MAX_ST 11

using namespace std;

int N, M, K;
int notebook[MAX][MAX];
int R, C;
int sticker[MAX_ST][MAX_ST];

bool check(int startY, int startX, int dir)
{
    int newR, newC;
    if (dir == 0 || dir == 2)
    {
        newR = R;
        newC = C;
    }
    else if (dir == 1 || dir == 3)
    {
        newR = C;
        newC = R;
    }

    for (int i = startY; i < startY + newR; i++)
    {
        for (int j = startX; j < startX + newC; j++)
        {
            if (i < 0 || i >= N || j < 0 || j >= M)
            {
                return false;
            }

            int newY = i - startY, newX = j - startX;
            if (dir == 1)
            {
                newY = R - 1 - (j - startX);
                newX = i - startY;
            }
            else if (dir == 2)
            {
                newY = R - 1 - (i - startY);
                newX = C - 1 - (j - startX);
            }
            else if (dir == 3)
            {
                newY = j - startX;
                newX = C - 1 - (i - startY);
            }

            if (sticker[newY][newX] == 1)
            {
                if (notebook[i][j] == 1)
                    return false;
            }
        }
    }
    
    for (int i = startY; i < startY + newR; i++)
    {
        for (int j = startX; j < startX + newC; j++)
        {
            int newY = i - startY, newX = j - startX;
            if (dir == 1)
            {
                newY = R - 1 - (j - startX);
                newX = i - startY;
            }
            else if (dir == 2)
            {
                newY = R - 1 - (i - startY);
                newX = C - 1 - (j - startX);
            }
            else if (dir == 3)
            {
                newY = j - startX;
                newX = C - 1 - (i - startY);
            }

            if (sticker[newY][newX] == 1)
            {
                notebook[i][j] = 1;
            }
        }
    }
    return true;
}

void func()
{
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                bool result = check(i, j, k);
                if (result)
                {
                    return;
                } 
            }
        }
    }
    
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int idx = 0; idx < K; idx++)
    {
        scanf("%d %d", &R, &C);
        for (int row = 0; row < R; row++)
        {
            for (int col = 0; col < C; col++)
            {
                scanf("%d", &sticker[row][col]);
            }
        }
        func();
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (notebook[i][j] == 1)
            {
                cnt++;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}