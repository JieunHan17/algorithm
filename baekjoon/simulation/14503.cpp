#include <cstdio>

#define MAX 51

using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dx[4] = {0, 1, 0, -1};
int m[MAX][MAX];
int cnt = 0;

int getLeft(int dir)
{
    if (dir == 0)
        return 3;
    else
        return dir - 1;
}

void search(int curY, int curX, int dir)
{
    if (m[curY][curX] == 0)
    {
        m[curY][curX] = -1;
        cnt++;
    }
        
    int curDir = dir;
    for (int i = 0; i < 4; i++)
    {
        int nextDir = getLeft(curDir);
        int nextY = curY + dy[nextDir];
        int nextX = curX + dx[nextDir];
        if (m[nextY][nextX] == 0)
        {
            search(nextY, nextX, nextDir);
            return;
        }
        curDir = nextDir;
    }
    int rearY = curY - dy[curDir];
    int rearX = curX - dx[curDir];
    if (m[rearY][rearX] == 1)
    {
        return;
    }
    else
    {
        search(rearY, rearX, curDir);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    int startY, startX, dir;
    scanf("%d %d %d", &startY, &startX, &dir);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    search(startY, startX, dir);
    printf("%d", cnt);
    return 0;
}