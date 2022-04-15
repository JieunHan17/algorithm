#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX_N 11
#define MAX_M 101

using namespace std;

int N, M, K;
int food[MAX_N][MAX_N]; // 양분
int ground[MAX_N][MAX_N];
vector<int> age[MAX_N][MAX_N];
vector<int> dead_age[MAX_N][MAX_N];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector<int> temp;
            for (int k = 0; k < age[i][j].size(); k++)
            {
                if (age[i][j][k] <= ground[i][j])
                {
                    ground[i][j] -= age[i][j][k];
                    temp.push_back(age[i][j][k] + 1);
                }
                else
                {
                    dead_age[i][j].push_back(age[i][j][k]);
                }
            }
            age[i][j] = temp;
        }
    }
}

void summer()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < dead_age[i][j].size(); k++)
            {
                ground[i][j] += (dead_age[i][j][k] / 2);
            }
        }
    }
}

void fall()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < age[i][j].size(); k++)
            {
                if (age[i][j][k] % 5 == 0)
                {
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int nextY = i + dy[dir];
                        int nextX = j + dx[dir];
                        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                        {
                            continue;
                        }
                        age[nextY][nextX].push_back(1);
                    }
                }
            }
        }
    }
}

void winter()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ground[i][j] += food[i][j];
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &food[i][j]);
            ground[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        age[x - 1][y - 1].push_back(z);
    }

    int year = 0;
    while (1)
    {
        if (year == K)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                sort(age[i][j].begin(), age[i][j].end());
                vector<int> v;
                dead_age[i][j] = v;
            }
        }
        spring();
        summer();
        fall();
        winter();
        year++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans += age[i][j].size();
        }
    }
    
    printf("%d", ans);
    return 0;
}