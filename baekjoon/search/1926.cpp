#include <cstdio>
#include <queue>
#include <utility>

#define MAX 501

using namespace std;

int paper[MAX][MAX];
bool visited[MAX][MAX] = {
    false,
};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int bfs(int startY, int startX, int n, int m)
{
    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;

    int area = 1;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
            {
                continue;
            }
            if (visited[nextY][nextX] || !paper[nextY][nextX])
            {
                continue;
            }
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
            area++;
        }
    }
    return area;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }

    int cnt = 0;
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (paper[i][j] && !visited[i][j])
            {
                maximum = max(maximum, bfs(i, j, n, m));
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    printf("%d", maximum);

    return 0;
}