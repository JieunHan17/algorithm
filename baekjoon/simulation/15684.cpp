#include <cstdio>
#include <algorithm>

#define MAX_N 11
#define MAX_H 31

using namespace std;

int N, M, H;
int board[MAX_H][MAX_N];
int dx[2] = {-1, 1}; // 왼쪽, 오른쪽
bool stop = false;
int ans = 4;

int getResult(int col)
{
    int curX = col;
    for (int i = 1; i <= H; i++)
    {
        int curMark = board[i][curX];
        if (curMark != 0)
        {
            for (int j = 0; j < 2; j++)
            {
                int nextX = curX + dx[j];
                if (nextX < 1 || nextX > N)
                {
                    continue;
                }
                if (board[i][nextX] == curMark)
                {
                    curX = nextX;
                    break;
                }
            }   
        }
    }
    return curX;
}

void dfs(int depth)
{
    bool success = true;
    for (int i = 1; i <= N; i++)
    {
        if (getResult(i) != i)
        {
            success = false;
            break;
        }
    }
    if (success)
    {
        ans = min(ans, depth);
        stop = true;
        return;
    }
    else if (depth == 3)
    {
        return;
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                int nextX = j + 1;
                if (board[i][nextX] == 0)
                {
                    board[i][j] = M + (depth + 1);
                    board[i][nextX] = M + (depth + 1);
                    dfs(depth + 1);
                    board[i][j] = 0;
                    board[i][nextX] = 0;
                    if (stop)
                    {
                        stop = false;
                        return;
                    } 
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &H);
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        board[a][b] = i;
        board[a][b + 1] = i;
    }

    dfs(0);
    ans = ans == 4 ? -1 : ans;
    printf("%d", ans);
    return 0;
}