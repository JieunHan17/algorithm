#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N, M, ans, limit;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int counted[50][50];
string board[50];

void dfs(int y, int x, int cnt)
{
    if (ans < cnt)
    {
        ans = cnt;
    }
    if (ans > limit)
    {
        return;
    }

    /* 예외처리 */
    if (y < 0 || N <= y || x < 0 || M <= x || board[y][x] == -1)
    {
        return;
    }
    if (cnt <= counted[y][x])
    {
        return;
    }
    counted[y][x] = cnt;
    int cur = board[y][x];
    for (int i = 0; i < 4; i++)
    {
        dfs(y + dy[i] * cur, x + dx[i] * cur, cnt + 1);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    limit = N * M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            counted[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'H')
            {
                board[i][j] = -1;
            }
            else
            {
                board[i][j] -= '0';
            }
        }
    }

    dfs(0, 0, 0);
    if (ans > limit)
    {
        ans = -1;
    }
    printf("%d\n", ans);

    return 0;
}