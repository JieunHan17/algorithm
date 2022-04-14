#include <cstdio>
#include <stack>
#include <vector>

#define MAX 1025

using namespace std;

bool board[101][101];
int dy[4] = {0, -1, 0, 1}; // 동북서남
int dx[4] = {1, 0, -1, 0};
int directions[MAX];

void getDirections(int dir, int gen)
{
    directions[0] = dir; // 0세대 고려
    for (int i = 1; i <= gen; i++)
    {
        stack<int> s;
        for (int j = 0; j < (1<<(i - 1)); j++)
        {
            s.push((directions[j] + 3) % 4);
        }

        int idx = 1<<(i - 1);
        while (!s.empty())
        {
            directions[idx] = s.top();
            s.pop();
            idx++;
        }
    }
}

void checkBoard(int startY, int startX, int dir, int gen)
{
    int curY = startY;
    int curX = startX;
    board[curY][curX] = true;
    for (int i = 0; i < (1<<gen); i++)
    {
        int nextY, nextX;
        if (dir == 0 || dir == 2)
        {
            if (directions[i] == 1 || directions[i] == 3) // 1과 3은 반대로 좌표 더하기
            {
                nextY = curY - dy[directions[i]];
                nextX = curX - dx[directions[i]];
            }
            else
            {
                nextY = curY + dy[directions[i]];
                nextX = curX + dx[directions[i]];
            }
        }
        else if (dir == 1 || dir == 3)
        {
            if (directions[i] == 0 || directions[i] == 2) // 0과 2는 반대로 좌표 더하기
            {
                nextY = curY - dy[directions[i]];
                nextX = curX - dx[directions[i]];
            }
            else
            {
                nextY = curY + dy[directions[i]];
                nextX = curX + dx[directions[i]];
            }
        }
        board[nextY][nextX] = true;
        curY = nextY;
        curX = nextX;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        getDirections(d, g);
        checkBoard(y, x, d, g);
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
            {
                ans++;
            }
        }
    }

    printf("%d", ans);
    return 0;
}

// 시간복잡도: ((10 * 2^9) + 2^10) * 20 + 100^2 = 102,400