#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define MAX 11

using namespace std;

int N, M;
string board[MAX];
int redY, redX, blueY, blueX;
int dy[4] = {0, 0, -1, 1}; // 왼쪽, 오른쪽, 위쪽, 아래쪽
int dx[4] = {-1, 1, 0, 0};
int dist[MAX][MAX][MAX][MAX];

int bfs()
{
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(redY, redX), make_pair(blueY, blueX)));
    dist[redY][redX][blueY][blueX] = 0;

    while (!q.empty())
    {
        int curRedY = q.front().first.first;
        int curRedX = q.front().first.second;
        int curBlueY = q.front().second.first;
        int curBlueX = q.front().second.second;
        q.pop();

        int cnt = dist[curRedY][curRedX][curBlueY][curBlueX];
        if (cnt >= 10)
            return -1;
        
        for (int i = 0; i < 4; i++)
        {
            int nextRedY = curRedY;
            int nextRedX = curRedX;
            int nextBlueY = curBlueY;
            int nextBlueX = curBlueX;

            while (board[nextBlueY + dy[i]][nextBlueX + dx[i]] == '.')
            {
                nextBlueY = nextBlueY + dy[i];
                nextBlueX = nextBlueX + dx[i];
            }

            if (board[nextBlueY + dy[i]][nextBlueX + dx[i]] == 'O')
            {
                continue;
            }

            while (board[nextRedY + dy[i]][nextRedX + dx[i]] == '.')
            {
                nextRedY = nextRedY + dy[i];
                nextRedX = nextRedX + dx[i];
            }

            if (board[nextRedY + dy[i]][nextRedX + dx[i]] == 'O')
            {
                return cnt + 1;
            }

            if (nextRedY == nextBlueY && nextRedX == nextBlueX)
            {
                if (i == 0) // 왼쪽
                {
                    curRedX < curBlueX ? nextBlueX++ : nextRedX++;
                }
                else if (i == 1) // 오른쪽
                {
                    curRedX < curBlueX ? nextRedX-- : nextBlueX--;
                }
                else if (i == 2) // 위쪽
                {
                    curRedY < curBlueY ? nextBlueY++ : nextRedY++;
                }
                else // 아래쪽
                {
                    curRedY < curBlueY ? nextRedY-- : nextBlueY--;
                }
            }

            if (dist[nextRedY][nextRedX][nextBlueY][nextBlueX] != -1)
            {
                continue;
            }
            dist[nextRedY][nextRedX][nextBlueY][nextBlueX] = cnt + 1;
            q.push(make_pair(make_pair(nextRedY, nextRedX), make_pair(nextBlueY, nextBlueX)));
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                redY = i;
                redX = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                blueY = i;
                blueX = j;
                board[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                fill(dist[i][j][k], dist[i][j][k] + 10, -1);
            }
        }
    }
    
    cout << bfs();
    return 0;
}