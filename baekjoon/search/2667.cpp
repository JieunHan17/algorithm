#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N = 0;
string line[25];
bool visited[25][25] = {
    false,
};
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};
int cnt = 0;
int apt_num = 0;
int num[800] = {
    0,
};

int bfs(int i, int j)
{
    apt_num = 0;
    queue<pair<int, int> > q;

    q.push(make_pair(i, j));
    visited[i][j] = true;
    apt_num++;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dir_x[i];
            int nextY = curY + dir_y[i];

            if (!visited[nextX][nextY] && 0 <= nextX && nextX <= (N - 1) && 0 <= nextY && nextY <= (N - 1) && line[nextX][nextY] == '1')
            {
                q.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = true;
                apt_num++;
            }
        }
    }

    return 0;
}

int main()
{
    int index = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        cin >> line[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && line[i][j] == '1')
            {
                bfs(i, j);
                cnt++;
                num[index] = apt_num;
                index++;
            }
        }
    }

    sort(num, num + cnt);
    printf("%d\n", cnt);
    for (int k = 0; k < cnt; k++)
    {
        printf("%d\n", num[k]);
    }

    return 0;
}