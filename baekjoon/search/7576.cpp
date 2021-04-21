#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int M = 0, N = 0;
int tomatoes[1000][1000] = {
    0,
};
bool visited[1000][1000] = {
    false,
};
int dir_x[4] = {-1, 1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
int day = 0;
queue<pair<int, int> > q;
queue<int> q_day;

int bfs(int start_x[], int start_y[], int num_of_1)
{
    for (int i = 0; i < num_of_1; i++)
    {
        q.push(make_pair(start_x[i], start_y[i]));
        q_day.push(day);
        visited[start_y[i]][start_x[i]] = true;
    }

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        int cur_day = q_day.front();
        q_day.pop();

        int next_day = cur_day + 1;
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dir_x[i];
            int next_y = cur_y + dir_y[i];
            if (!visited[next_y][next_x] && tomatoes[next_y][next_x] == 0 && 0 <= next_x && next_x <= (M - 1) && 0 <= next_y && next_y <= (N - 1))
            {
                q.push(make_pair(next_x, next_y));
                q_day.push(next_day);
                visited[next_y][next_x] = true;
                tomatoes[next_y][next_x] = 1;
            }
        }
        day = cur_day;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &M, &N);

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            scanf("%d", &tomatoes[y][x]);
        }
    }

    int start_x[M * N], start_y[M * N];
    fill(start_x, start_x + M * N, 0);
    fill(start_y, start_y + M * N, 0);
    int num_of_1 = 0;
    bool flag = false;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (tomatoes[y][x] == 1)
            {
                start_x[num_of_1] = x;
                start_y[num_of_1] = y;
                num_of_1++;
            }

            if (tomatoes[y][x] == 0)
            {
                flag = true;
            }
        }
    }

    if (flag == false)
    {
        printf("0");
    }
    else
    {
        bfs(start_x, start_y, num_of_1);

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (visited[y][x] == false && tomatoes[y][x] != -1)
                {
                    printf("-1");
                    return 0;
                }
            }
        }

        printf("%d", day);
    }

    return 0;
}