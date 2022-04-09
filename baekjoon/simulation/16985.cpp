#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX 987654

using namespace std;

int maze[5][5][5];
int maze_copy[4][5][5][5];
int dz[6] = {-1, 0, 1, 0, 0, 0}; // 위, 동, 아, 서, 앞, 뒤
int dy[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 1, 0, -1, 0, 0};

bool OOB(int x)
{
    if (x < 0 || x >= 5)
        return true;
    else
        return false;
}

int bfs()
{
    int dist[5][5][5] = {0,};

    if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
        return MAX;

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(0, 0)));
    dist[0][0][0] = 1;

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
            if (OOB(nextZ) || OOB(nextY) || OOB(nextX))
            {
                continue;
            }
            if (dist[nextZ][nextY][nextX] != 0 || maze[nextZ][nextY][nextX] == 0)
            {
                continue;
            }
            if (nextZ == 4 && nextY == 4 && nextX == 4)
            {
                return dist[curZ][curY][curX];
            }
            q.push(make_pair(nextZ, make_pair(nextY, nextX)));
            dist[nextZ][nextY][nextX] = dist[curZ][curY][curX] + 1;
        }
    }

    return MAX;
}

int main()
{
    // 입력 받기
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                scanf("%d", &maze_copy[0][i][j][k]);
            }
        }
    }

    // 방향 돌리기 사전 작업
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                maze_copy[1][i][j][k] = maze_copy[0][i][5 - 1 - k][j];
            }
        }

        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                maze_copy[2][i][j][k] = maze_copy[1][i][5 - 1 - k][j];
            }
        }

        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                maze_copy[3][i][j][k] = maze_copy[2][i][5 - 1 - k][j];
            }
        }
    }

    int order[5] = {0,1,2,3,4};

    int ans = MAX;
    do
    {
        for (int temp = 0; temp < (1 << (2 * 5)); temp++)
        {
            int brute = temp;
            for (int i = 0; i < 5; i++)
            {
                int dir = brute % 4;
                brute /= 4;
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        maze[i][j][k] = maze_copy[dir][order[i]][j][k];
                    }
                }
            }
            ans = min(ans, bfs());
        }
    } while (next_permutation(order, order+5));

    if (ans == MAX)
        ans = -1;
    printf("%d", ans);

    return 0;
}