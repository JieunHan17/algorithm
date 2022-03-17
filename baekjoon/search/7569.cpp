#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 101

using namespace std;

int tomatoes[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main()
{
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                scanf("%d", &tomatoes[i][j][k]);
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fill(dist[i][j], dist[i][j] + M, -1);
        }
    }

    queue<pair<int, pair<int, int> > > q;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomatoes[i][j][k] == 1)
                {
                    q.push(make_pair(i, make_pair(j, k)));
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    int days = 0;
    while (!q.empty())
    {
        int curZ = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nextZ = curZ + dz[i];
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextZ < 0 || nextZ >= H || nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
            {
                continue;
            }
            if (dist[nextZ][nextY][nextX] >= 0)
            {
                continue;
            }
            if (tomatoes[nextZ][nextY][nextX] == 0)
            {
                q.push(make_pair(nextZ, make_pair(nextY, nextX)));
                dist[nextZ][nextY][nextX] = dist[curZ][curY][curX] + 1;
                days = dist[nextZ][nextY][nextX];
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomatoes[i][j][k] == 0 && dist[i][j][k] == -1)
                {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    printf("%d", days);
    return 0;
}