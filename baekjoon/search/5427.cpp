#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 1001

using namespace std;

char building[MAX][MAX];
int dist_F[MAX][MAX];
int dist_S[MAX][MAX];
int dy[4] = {0, 0, 1, -1}; //동서남북
int dx[4] = {1, -1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int w, h;
        cin >> w >> h;

        for (int i = 0; i < h; i++)
        {
            fill(dist_F[i], dist_F[i] + w, -1);
            fill(dist_S[i], dist_S[i] + w, -1);
        }

        for (int i = 0; i < h; i++)
        {
            cin >> building[i];
        }

        queue<pair<int, int> > q_F;
        queue<pair<int, int> > q_S;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (building[i][j] == '*')
                {
                    dist_F[i][j] = 0;
                    q_F.push(make_pair(i, j));
                }
                else if (building[i][j] == '@')
                {
                    dist_S[i][j] = 0;
                    q_S.push(make_pair(i, j));
                }
            }
        }

        while (!q_F.empty())
        {
            int curY = q_F.front().first;
            int curX = q_F.front().second;
            q_F.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];
                if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
                {
                    continue;
                }
                if (dist_F[nextY][nextX] >= 0 || building[nextY][nextX] == '#')
                {
                    continue;
                }
                q_F.push(make_pair(nextY, nextX));
                dist_F[nextY][nextX] = dist_F[curY][curX] + 1;
            }
        }

        bool flag = false;
        while (!q_S.empty())
        {
            if (!flag)
            {
                int curY = q_S.front().first;
                int curX = q_S.front().second;
                q_S.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nextY = curY + dy[i];
                    int nextX = curX + dx[i];
                    if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
                    {
                        cout << dist_S[curY][curX] + 1 << '\n';
                        flag = true;
                        break;
                    }
                    if (dist_S[nextY][nextX] >= 0 || building[nextY][nextX] == '#')
                    {
                        continue;
                    }
                    if (dist_F[nextY][nextX] != -1 && dist_S[curY][curX] + 1 >= dist_F[nextY][nextX])
                    {
                        continue;
                    }
                    q_S.push(make_pair(nextY, nextX));
                    dist_S[nextY][nextX] = dist_S[curY][curX] + 1;
                }
            }
            else
            {
                break;
            }
        }
        if (!flag)
        {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}