#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 301

using namespace std;

int ocean[MAX][MAX];
bool visited[MAX][MAX];
bool visited2[MAX][MAX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int getNumOfGroups(int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        fill(visited[i], visited[i] + M, false);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ocean[i][j] != 0 && !visited[i][j])
            {
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                while (!q.empty())
                {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nextY = curY + dy[i];
                        int nextX = curX + dx[i];
                        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                        {
                            continue;
                        }
                        if (!visited[nextY][nextX] && ocean[nextY][nextX] != 0)
                        {
                            q.push(make_pair(nextY, nextX));
                            visited[nextY][nextX] = true;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    return cnt;
}

bool melt(int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        fill(visited2[i], visited2[i] + M, false);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ocean[i][j] == 0 && !visited2[i][j])
            {
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited2[i][j] = true;
                while (!q.empty())
                {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nextY = curY + dy[i];
                        int nextX = curX + dx[i];
                        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                        {
                            continue;
                        }
                        if (visited2[nextY][nextX])
                        {
                            continue;
                        }
                        if (ocean[nextY][nextX] > 0)
                        {
                            ocean[nextY][nextX]--;
                            if (ocean[nextY][nextX] == 0)
                            {
                                visited2[nextY][nextX] = true;
                            }
                        }
                        else
                        {
                            q.push(make_pair(nextY, nextX));
                            visited2[nextY][nextX] = true;
                        }
                    }
                }
            }
        }
    }

    bool isMeltedAll = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ocean[i][j] > 0)
            {
                isMeltedAll = false;
            }
        }
    }

    return isMeltedAll;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &ocean[i][j]);
        }
    }

    int year = 0;
    int numOfGroups = getNumOfGroups(N, M);
    while (numOfGroups < 2)
    {
        bool isMeltedAll = melt(N, M);
        year++;
        numOfGroups = getNumOfGroups(N, M);

        if (isMeltedAll && numOfGroups < 2)
        {
            printf("0");
            return 0;
        }
    }

    printf("%d", year);

    return 0;
}