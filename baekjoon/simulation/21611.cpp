#include <cstdio>
#include <algorithm>

#define MAX_N 50

using namespace std;

int N, M;
int board[MAX_N][MAX_N];
int temp[MAX_N * MAX_N] = {0,};
int sharkY, sharkX;
int dy[5] = {0, -1, 1, 0, 0}; // X, 북, 남, 서, 동
int dx[5] = {0, 0, 0, -1, 1};
int dirY[4] = {0, 1, 0, -1}; // 서, 남, 동, 북
int dirX[4] = {-1, 0, 1, 0};
int beads[4];

void removeBeads(int d, int s)
{
    int curY = sharkY;
    int curX = sharkX;
    while (s--)
    {
        int nextY = curY + dy[d];
        int nextX = curX + dx[d];
        board[nextY][nextX] = 0;
        curY = nextY;
        curX = nextX;
    }
}

void flatten()
{
    int limit1 = N * 2 - 1;
    int dir = 0;
    int curY = sharkY;
    int curX = sharkX;

    int idx = 1;
    for (int i = 0; i < limit1; i++)
    {
        int limit2 = i == limit1 - 1 ? i / 2 : i / 2 + 1;
        for (int j = 0; j < limit2; j++)
        {
            int nextY = curY + dirY[dir];
            int nextX = curX + dirX[dir];
            temp[idx] = board[nextY][nextX];
            curY = nextY;
            curX = nextX;
            idx++;
        }
        dir = (dir + 1) % 4;
    }
}

void moveBeads()
{
    int left = 1;
    int right = 1;
    while (left < N * N)
    {
        if (temp[left] == 0)
        {
            right = left + 1;
            while (right < N * N)
            {
                if (temp[right] != 0)
                {
                    swap(temp[left], temp[right]);
                    break;
                }
                right++;
            }
        }
        left++;
    }
}

bool explodeBeads()
{
    bool isThereExplosion = false;
    int left = 1;
    int right = 2;
    while (right < N * N)
    {
        if (temp[left] == temp[right])
        {
            right++;
        }
        else
        {
            if (right - left >= 4)
            {
                isThereExplosion = true;
                beads[temp[left]] += (right - left);
                for (int i = left; i < right; i++)
                {
                    temp[i] = 0;
                }
            }
            left = right;
            right = left + 1;
        }
    }
    return isThereExplosion;
}

void changeBeads()
{
    int temp_copy[MAX_N * MAX_N] = {0,};
    int idx = 1;
    int left = 1;
    int right = 2;
    while (right < N * N)
    {
        if (temp[left] == temp[right])
        {
            right++;
        }
        else
        {
            temp_copy[idx] = right - left;
            idx++;
            if (idx >= N * N)
            {
                break;
            }
            temp_copy[idx] = temp[left];
            idx++;
            if (idx >= N * N)
            {
                break;
            }
            left = right;
            right = left + 1;
        }
    }
    for (int i = 0; i < N * N; i++)
    {
        temp[i] = temp_copy[i];
    }
}

void backToBoard()
{
    int limit1 = N * 2 - 1;
    int dir = 0;
    int curY = sharkY;
    int curX = sharkX;

    int idx = 1;
    for (int i = 0; i < limit1; i++)
    {
        int limit2 = i == limit1 - 1 ? i / 2 : i / 2 + 1;
        for (int j = 0; j < limit2; j++)
        {
            int nextY = curY + dirY[dir];
            int nextX = curX + dirX[dir];
            board[nextY][nextX] = temp[idx];
            curY = nextY;
            curX = nextX;
            idx++;
        }
        dir = (dir + 1) % 4;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    sharkY = (N+1)/2;
    sharkX = (N+1)/2;
    while (M--)
    {
        int d, s;
        scanf("%d %d", &d, &s);
        removeBeads(d, s);
        flatten();
        moveBeads();
        while (1)
        {
            bool isThereExplosion = explodeBeads();
            if (!isThereExplosion)
            {
                break;
            }
            moveBeads();
        }
        changeBeads();
        backToBoard();
    }
    printf("%d", beads[1] + 2 * beads[2] + 3 * beads[3]);
    return 0;
}