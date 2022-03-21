#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 101
#define MAX_VALUE 987654321

using namespace std;

int m[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void categorize(int N, int startY, int startX, int num)
{
    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        m[curY][curX] = num;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
            {
                continue;
            }
            if (visited[nextY][nextX])
            {
                continue;
            }
            if (m[nextY][nextX] == 1)
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }
}

int getMinDist(int N)
{
    queue<pair<int, int> > q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (m[i][j] != 0)
            {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    int minimum = MAX_VALUE;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
            {
                continue;
            }
            if (m[nextY][nextX] == m[curY][curX])
            {
                continue;
            }
            if (m[nextY][nextX] != 0)
            {
                minimum = min(minimum, dist[curY][curX] + dist[nextY][nextX]);
            }
            else
            {
                m[nextY][nextX] = m[curY][curX];
                q.push(make_pair(nextY, nextX));
                dist[nextY][nextX] = dist[curY][curX] + 1;
            }
        }
    }

    return minimum;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        fill(visited[i], visited[i] + N, false);
    }

    int num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (m[i][j] == 1 && !visited[i][j])
            {
                num++;
                categorize(N, i, j, num);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        fill(dist[i], dist[i] + N, -1);
    }

    int ans = getMinDist(N);
    printf("%d", ans);

    return 0;
}