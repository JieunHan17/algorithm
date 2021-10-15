#include <cstdio>
#include <queue>
#include <utility>

#define MAX 100

using namespace std;

int N, M;
int paper[MAX][MAX] = {
    0,
};
bool visited[MAX][MAX] = {
    false,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int start_y, int start_x)
{
    visited[start_y][start_x] = true;
    paper[start_y][start_x] = 2;

    for (int i = 0; i < 4; i++)
    {
        int next_y = start_y + dy[i];
        int next_x = start_x + dx[i];
        if (next_y < 0 || N - 1 < next_y || next_x < 0 || M - 1 < next_x)
        {
            continue;
        }
        if (visited[next_y][next_x])
        {
            continue;
        }
        if (paper[next_y][next_x] == 0)
        {
            DFS(next_y, next_x);
        }
    }
    return;
}

void BFS(int start_y, int start_x)
{
    queue<pair<int, int> > q;
    q.push(make_pair(start_y, start_x));
    visited[start_y][start_x] = true;

    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        paper[cur_y][cur_x] = 2;

        for (int i = 0; i < 4; i++)
        {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if (next_y < 0 || N - 1 < next_y || next_x < 0 || M - 1 < next_x)
            {
                continue;
            }
            if (visited[next_y][next_x])
            {
                continue;
            }
            if (paper[next_y][next_x] == 0)
            {
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    int num_of_cheese = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &paper[i][j]);
            if (paper[i][j] == 1)
            {
                num_of_cheese++;
            }
        }
    }

    int total_time = 0;
    while (num_of_cheese > 0)
    {
        BFS(0, 0);

        int cnt_deleted = 0;
        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                if (paper[i][j] == 1)
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int next_y = i + dy[k];
                        int next_x = j + dx[k];
                        if (paper[next_y][next_x] == 2)
                        {
                            cnt++;
                        }
                    }
                    if (cnt >= 2)
                    {
                        paper[i][j] = -1;
                        cnt_deleted++;
                    }
                }
            }
        }

        total_time++;
        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < M - 1; j++)
            {
                if (paper[i][j] == -1)
                {
                    paper[i][j] = 0;
                    num_of_cheese--;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (paper[i][j] == 2)
                {
                    paper[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                visited[i][j] = false;
            }
        }
    }

    printf("%d\n", total_time);

    return 0;
}