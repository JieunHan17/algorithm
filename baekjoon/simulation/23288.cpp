#include <cstdio>
#include <queue>
#include <utility>

#define MAX 21

using namespace std;

int N, M, K;
int board[MAX][MAX];
int dice[6] = {1, 3, 6, 4, 2, 5}; // 주사위 아랫면: 6(인덱스 2)
int dy[4] = {-1, 0, 1, 0}; // 북동남서
int dx[4] = {0, 1, 0, -1};

int getOppositeDir(int dir)
{
    if (dir == 0)
    {
        return 2;
    }
    else if (dir == 1)
    {
        return 3;
    }
    else if (dir == 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void rollDice(int dir)
{
    int dice_copy[6] = {0,};
    if (dir == 0)
    {
        dice_copy[0] = dice[5];
        dice_copy[1] = dice[1];
        dice_copy[2] = dice[4];
        dice_copy[3] = dice[3];
        dice_copy[4] = dice[0];
        dice_copy[5] = dice[2];
    }
    else if (dir == 1)
    {
        dice_copy[0] = dice[3];
        dice_copy[1] = dice[0];
        dice_copy[2] = dice[1];
        dice_copy[3] = dice[2];
        dice_copy[4] = dice[4];
        dice_copy[5] = dice[5];
    }
    else if (dir == 2)
    {
        dice_copy[0] = dice[4];
        dice_copy[1] = dice[1];
        dice_copy[2] = dice[5];
        dice_copy[3] = dice[3];
        dice_copy[4] = dice[2];
        dice_copy[5] = dice[0];
    }
    else if (dir == 3)
    {
        dice_copy[0] = dice[1];
        dice_copy[1] = dice[2];
        dice_copy[2] = dice[3];
        dice_copy[3] = dice[0];
        dice_copy[4] = dice[4];
        dice_copy[5] = dice[5];
    }
    for (int i = 0; i < 6; i++)
    {
        dice[i] = dice_copy[i];
    }
}

int getScore(int y, int x)
{
    int num = board[y][x];

    queue<pair<int, int> > q;
    q.push(make_pair(y, x));

    bool visited[MAX][MAX] = {false,};
    visited[y][x] = true;

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 1 || nextY > N || nextX < 1 || nextX > M)
            {
                continue;
            }
            if (!visited[nextY][nextX] && board[nextY][nextX] == num)
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (visited[i][j])
            {
                cnt++;
            }
        }
    }

    return num * cnt;
}

int decideNexDir(int y, int x, int dir)
{
    int A = dice[2];
    int B = board[y][x];
    if (A > B)
    {
        return (dir + 1) % 4;
    }
    else if (A < B)
    {
        return (dir + 3) % 4;
    }
    else
    {
        return dir;
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int total = 0;
    int dir = 1;
    int curY = 1, curX = 1;
    while (K--)
    {
        int nextY = curY + dy[dir];
        int nextX = curX + dx[dir];
        if (nextY < 1 || nextY > N || nextX < 1 || nextX > M)
        {
            dir = getOppositeDir(dir);
            nextY = curY + dy[dir];
            nextX = curX + dx[dir];
        }
        curY = nextY;
        curX = nextX;
        rollDice(dir);
        total += getScore(curY, curX);
        dir = decideNexDir(curY, curX, dir);
    }
    printf("%d", total);
    return 0;
}