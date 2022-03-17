#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 1001
#define MAX_VALUE 987654321

using namespace std;

char m[MAX][MAX];
int dist[MAX][MAX][2];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int bfs(int N, int M)
{
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 0));
    dist[0][0][0] = dist[0][0][1] = 1;

    while (!q.empty())
    {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int isBroken = q.front().second;
        q.pop();

        if (curY == N - 1 && curX == M - 1)
        {
            return dist[curY][curX][isBroken];
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
            {
                continue;
            }
            if (dist[nextY][nextX][isBroken] == -1 && m[nextY][nextX] == '0')
            {
                q.push(make_pair(make_pair(nextY, nextX), isBroken));
                dist[nextY][nextX][isBroken] = dist[curY][curX][isBroken] + 1;
            }
            if (!isBroken && m[nextY][nextX] == '1' && dist[nextY][nextX][1] == -1)
            {
                q.push(make_pair(make_pair(nextY, nextX), 1));
                dist[nextY][nextX][1] = dist[curY][curX][isBroken] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }

    cout << bfs(N, M);

    return 0;
}