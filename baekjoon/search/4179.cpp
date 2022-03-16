#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 1001

using namespace std;

char maze[MAX][MAX];
int dist_F[MAX][MAX];
int dist_J[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> maze[i];
    }

    for (int i = 0; i < R; i++)
    {
        fill(dist_F[i], dist_F[i] + C, -1);
        fill(dist_J[i], dist_J[i] + C, -1);
    }

    queue<pair<int, int> > queue_F;
    queue<pair<int, int> > queue_J;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == 'F')
            {
                dist_F[i][j] = 0;
                queue_F.push(make_pair(i, j));
            }
            else if (maze[i][j] == 'J')
            {
                dist_J[i][j] = 0;
                queue_J.push(make_pair(i, j));
            }
        }
    }

    while (!queue_F.empty())
    {
        int curY = queue_F.front().first;
        int curX = queue_F.front().second;
        queue_F.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
            {
                continue;
            }
            if (maze[nextY][nextX] == '#' || dist_F[nextY][nextX] >= 0)
            {
                continue;
            }
            dist_F[nextY][nextX] = dist_F[curY][curX] + 1;
            queue_F.push(make_pair(nextY, nextX));
        }
    }

    while (!queue_J.empty())
    {
        int curY = queue_J.front().first;
        int curX = queue_J.front().second;
        queue_J.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
            {
                cout << dist_J[curY][curX] + 1;
                return 0;
            }
            if (maze[nextY][nextX] == '#' || dist_J[nextY][nextX] >= 0)
            {
                continue;
            }
            if (dist_F[nextY][nextX] != -1 && dist_J[curY][curX] + 1 >= dist_F[nextY][nextX])
            {
                continue;
            }
            dist_J[nextY][nextX] = dist_J[curY][curX] + 1;
            queue_J.push(make_pair(nextY, nextX));
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}