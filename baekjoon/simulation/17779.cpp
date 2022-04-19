#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

#define MAX_N 21
#define MAX 98765

using namespace std;

int N;
int A[MAX_N][MAX_N];
int section[MAX_N][MAX_N]; // 경계선: -1
bool visited[MAX_N][MAX_N];
int dy[4] = {-1, 0, 1, 0}; // 북동남서
int dx[4] = {0, 1, 0, -1};

bool check(int x, int y, int d1, int d2)
{
    if (x < x + d1 + d2 && x + d1 + d2 <= N && 1 <= y - d1 && y + d2 <= N)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void colorBoundary(int x, int y, int d1, int d2)
{
    int i, j;

    i = x;
    j = y;
    for (int idx = 0; idx <= d1; idx++)
    {
        // 왼쪽 위 대각선 -> d1개
        section[i][j] = -1;
        visited[i][j] = true;
        i += 1;
        j -= 1;
    }

    i = x;
    j = y;
    for (int idx = 0; idx <= d2; idx++)
    {
        // 오른쪽 위 대각선 -> d2개
        section[i][j] = -1;
        visited[i][j] = true;
        i += 1;
        j += 1;
    }

    i = x + d1;
    j = y - d1;
    for (int idx = 0; idx <= d2; idx++)
    {
        // 왼쪽 아래 대각선 -> d2개
        section[i][j] = -1;
        visited[i][j] = true;
        i += 1;
        j += 1;
    }

    i = x + d2;
    j = y + d2;
    for (int idx = 0; idx <= d1; idx++)
    {
        // 오른쪽 아래 대각선 -> d1개
        section[i][j] = -1;
        visited[i][j] = true;
        i += 1;
        j -= 1;
    }
}

void colorOne(int x, int y, int d1, int d2)
{
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    section[1][1] = 1;
    
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 1 || nextY >= x + d1 || nextX < 1 || nextX > y)
            {
                continue;
            }
            if (visited[nextY][nextX] || section[nextY][nextX] == -1)
            {
                continue;
            }
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
            section[nextY][nextX] = 1;
        }
    }
}

void colorTwo(int x, int y, int d1, int d2)
{
    queue<pair<int, int> > q;
    q.push(make_pair(1, N));
    visited[1][N] = true;
    section[1][N] = 2;
    
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 1 || nextY > x + d2 || nextX <= y || nextX > N)
            {
                continue;
            }
            if (visited[nextY][nextX] || section[nextY][nextX] == -1)
            {
                continue;
            }
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
            section[nextY][nextX] = 2;
        }
    }
}

void colorThree(int x, int y, int d1, int d2)
{
    queue<pair<int, int> > q;
    q.push(make_pair(N, 1));
    visited[N][1] = true;
    section[N][1] = 3;
    
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < x + d1 || nextY > N || nextX < 1 || nextX >= y - d1 + d2)
            {
                continue;
            }
            if (visited[nextY][nextX] || section[nextY][nextX] == -1)
            {
                continue;
            }
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
            section[nextY][nextX] = 3;
        }
    }
}

void colorFour(int x, int y, int d1, int d2)
{
    queue<pair<int, int> > q;
    q.push(make_pair(N, N));
    visited[N][N] = true;
    section[N][N] = 4;
    
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY <= x + d2 || nextY > N || nextX < y - d1 + d2 || nextX > N)
            {
                continue;
            }
            if (visited[nextY][nextX] || section[nextY][nextX] == -1)
            {
                continue;
            }
            visited[nextY][nextX] = true;
            q.push(make_pair(nextY, nextX));
            section[nextY][nextX] = 4;
        }
    }
}

int getDiff()
{
    unordered_map<int, int> m;
    for (int i = 1; i <= 5; i++)
    {
        m[i] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cell = section[i][j];
            if (cell == -1)
            {
                cell = 5;
            }
            m[cell] += A[i][j];
        }
    }

    int maximum = 0;
    int minimum = MAX;
    for (int i = 1; i <= 5; i++)
    {
        maximum = max(maximum, m[i]);
        minimum = min(minimum, m[i]);
    }

    return maximum - minimum;
}

int main()
{   
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    /* 기준점과 경계의 길이 정하기 */
    int ans = MAX;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x = i;
            int y = j;
            
            int d1 = 1;
            while (1)
            {
                int d2 = 1;
                int cnt = 0;
                while (1)
                {
                    if (!check(x, y, d1, d2))
                    {
                        break;
                    }

                    for (int i = 1; i <= N; i++)
                    {
                        fill(visited[i], visited[i] + N + 1, false);
                        fill(section[i], section[i] + N + 1, 0);
                    }
                    colorBoundary(x, y, d1, d2);
                    colorOne(x, y, d1, d2);
                    colorTwo(x, y, d1, d2);
                    colorThree(x, y, d1, d2);
                    colorFour(x, y, d1, d2);
                    for (int i = 1; i <= N; i++)
                    {
                        for (int j = 1; j <= N; j++)
                        {
                            if (section[i][j] == 0)
                            {
                                section[i][j] = 5;
                            }
                        }
                    }
                    ans = min(ans, getDiff());
                    d2++;
                    cnt++;
                }
                if (cnt == 0)
                {
                    break;
                }
                d1++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}