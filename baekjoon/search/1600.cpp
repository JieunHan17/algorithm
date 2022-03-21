#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX_LENGTH 201
#define MAX_K 31

using namespace std;

int board[MAX_LENGTH][MAX_LENGTH];
int dist[MAX_LENGTH][MAX_LENGTH][MAX_K];
int dirY_horse[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dirX_horse[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dirY[4] = {0, 0, 1, -1};
int dirX[4] = {1, -1, 0, 0};

int main()
{
    int K, W, H;
    scanf("%d", &K);
    scanf("%d %d", &W, &H);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                dist[i][j][k] = -1;
            }
        }
    }

    // bfs
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0, 0), 0)); // y좌표, x좌표, 말처럼 이동한 횟수
    for (int k = 0; k <= K; k++)
    {
        dist[0][0][k] = 0;
    }
    while (!q.empty())
    {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curCnt = q.front().second;
        q.pop();

        if (curY == H - 1 && curX == W - 1)
        {
            printf("%d", dist[curY][curX][curCnt]);
            return 0;
        }

        if (curCnt < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nextY = curY + dirY_horse[i];
                int nextX = curX + dirX_horse[i];
                if (nextY < 0 || nextY >= H || nextX < 0 || nextX >= W)
                {
                    continue;
                }
                if (dist[nextY][nextX][curCnt + 1] >= 0 || board[nextY][nextX] == 1)
                {
                    continue;
                }
                q.push(make_pair(make_pair(nextY, nextX), curCnt + 1));
                dist[nextY][nextX][curCnt + 1] = dist[curY][curX][curCnt] + 1;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            if (nextY < 0 || nextY >= H || nextX < 0 || nextX >= W)
            {
                continue;
            }
            if (dist[nextY][nextX][curCnt] >= 0 || board[nextY][nextX] == 1)
            {
                continue;
            }
            q.push(make_pair(make_pair(nextY, nextX), curCnt));
            dist[nextY][nextX][curCnt] = dist[curY][curX][curCnt] + 1;
        }
    }

    printf("-1");
    return 0;
}