#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int vege[50][50] = {
    0,
};

int bfs(int M, int N)
{
    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, -1, 0, 1};
    bool visited[50][50] = {
        false,
    };
    int cnt = 0;

    queue<pair<int, int> > q;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (!visited[i][j] && vege[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visited[i][j] = true;

                while (!q.empty())
                {
                    int curX = q.front().first;
                    int curY = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int nextX = curX + dir_x[i];
                        int nextY = curY + dir_y[i];

                        if (!visited[nextX][nextY] && 0 <= nextX && nextX <= (M - 1) && 0 <= nextY && nextY <= (N - 1) && vege[curX][curY] == 1 && vege[nextX][nextY] == 1)
                        {
                            q.push(make_pair(nextX, nextY));
                            visited[nextX][nextY] = true;
                        }
                    }
                }

                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int T;
    int M, N, K;
    int x, y;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &M, &N, &K);

        fill(vege[0], vege[N], 0);

        for (int j = 0; j < K; j++)
        {
            scanf("%d %d", &x, &y);
            vege[x][y] = 1;
        }

        printf("%d\n", bfs(M, N));
    }
    return 0;
}