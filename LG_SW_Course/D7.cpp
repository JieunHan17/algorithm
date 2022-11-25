#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define MAXN (50)

int R, C; //지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10];
int dist_artist[MAXN + 10][MAXN + 10];
int dist_flood[MAXN + 10][MAXN + 10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> map[i];
    }
}

void Initialize()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dist_artist[i][j] = -1;
            dist_flood[i][j] = -1;
        }
    }
}

int BFS()
{
    queue<pair<int, int> > q_artist;
    queue<pair<int, int> > q_flood;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'S')
            {
                q_artist.push(make_pair(i, j));
                dist_artist[i][j] = 0;
            }
            else if (map[i][j] == '*')
            {
                q_flood.push(make_pair(i, j));
                dist_flood[i][j] = 0;
            }
        }
    }

    while (!q_flood.empty())
    {
        int curY = q_flood.front().first;
        int curX = q_flood.front().second;
        q_flood.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= R || nextX < 0 || nextY >= C)
            {
                continue;
            }
            if (map[nextY][nextX] == 'X' || map[nextY][nextX] == 'D')
            {
                continue;
            }
            if (dist_flood[nextY][nextX] >= 0)
            {
                continue;
            }
            q_flood.push(make_pair(nextY, nextX));
            dist_flood[nextY][nextX] = dist_flood[curY][curX] + 1;
        }
    }

    while (!q_artist.empty())
    {
        int curY = q_artist.front().first;
        int curX = q_artist.front().second;
        q_artist.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= R || nextX < 0 || nextY >= C)
            {
                continue;
            }
            if (dist_artist[nextY][nextX] >= 0)
            {
                continue;
            }
            if (map[nextY][nextX] == 'X')
            {
                continue;
            }
            if (dist_flood[nextY][nextX] >= 0 && dist_flood[nextY][nextX] <= dist_artist[curY][curX] + 1)
            {
                continue;
            }
            if (map[nextY][nextX] == 'D')
            {
                return dist_artist[curY][curX] + 1;
            }
            q_artist.push(make_pair(nextY, nextX));
            dist_artist[nextY][nextX] = dist_artist[curY][curX] + 1;
        }
    }
    return -1;
}

int main()
{
    int T, ans = -1;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        InputData(); //입력 받는 부분

        // 여기서부터 작성
        Initialize();
        ans = BFS();
        
        if (ans == -1)
            cout << "KAKTUS" << endl; //출력 하는 부분
        else
            cout << ans << endl;
    }
    return 0;
}