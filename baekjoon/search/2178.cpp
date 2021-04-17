#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;
string line[100];
bool visited[100][100] = {
    false,
};
int checked[100][100] = {
    0,
};
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};

int bfs(int y, int x)
{
    queue<pair<int, int> > q;

    q.push(make_pair(y, x));
    visited[y][x] = true;

    while (!q.empty())
    {
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];

            if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && line[nextY][nextX] == '1' && !visited[nextY][nextX] && checked[nextY][nextX] == 0)
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
                checked[nextY][nextX] = checked[curY][curX] + 1;
            }
        }
    }

    return checked[N - 1][M - 1] + 1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        cin >> line[i];
    }

    printf("%d", bfs(0, 0));

    return 0;
}