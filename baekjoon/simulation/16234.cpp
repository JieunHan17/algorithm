#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

#define MAX_N 51

using namespace std;

int N, L, R;
int ground[MAX_N][MAX_N];
int wall[MAX_N][MAX_N][4];
int dy[4] = {-1, 0, 1, 0}; // 북동남서
int dx[4] = {0, 1, 0, -1};
bool visited[MAX_N][MAX_N];
bool stop = true;
int ans = 0;

void movePeople(int startY, int startX)
{
    vector<pair<int, int> > countries;
    countries.push_back(make_pair(startY, startX));

    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
            {
                continue;
            }
            if (wall[curY][curX][i] == 1 && !visited[nextY][nextX])
            {
                countries.push_back(make_pair(nextY, nextX));
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }
    if (countries.size() == 1)
    {
        return;
    }
    
    int total = 0;
    for (int i = 0; i < countries.size(); i++)
    {
        total += ground[countries[i].first][countries[i].second];
    }
    
    int population = total / countries.size();
    for (int i = 0; i < countries.size(); i++)
    {
        if (ground[countries[i].first][countries[i].second] != total)
        {
            ground[countries[i].first][countries[i].second] = population;
            stop = false;
        } 
    }
}

int main()
{
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &ground[i][j]);
        }
    }

    while (1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = false;
                for (int k = 0; k < 4; k++)
                {
                    wall[i][j][k] = 0;
                }
            }
        }

        bool isOpen = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nextY = i + dy[k];
                    int nextX = j + dx[k];
                    if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                    {
                        continue;
                    }
                    if (wall[i][j][k] != 0)
                    {
                        continue;
                    }
                    
                    int diff = abs(ground[i][j] - ground[nextY][nextX]);
                    if (diff >= L && diff <= R)
                    {
                        isOpen = true;
                        wall[i][j][k] = 1;
                        wall[nextY][nextX][(k + 2) % 4] = 1;
                    }
                }
            }
        }

        if (!isOpen)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    movePeople(i, j);
                }
            }
        }
        ans++;

        if (stop)
        {
            break;
        }

        stop = true;
    }

    printf("%d", ans);
    return 0;
}