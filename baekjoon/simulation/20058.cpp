#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 65

using namespace std;

int N, Q;
int A[MAX][MAX];
int A_copy[MAX][MAX];
int length;
int dy[4] = {0, -1, 0, 1}; //동북서남
int dx[4] = {1, 0, -1, 0};
bool visited[MAX][MAX];

void rotateBoard(int startY, int startX, int small_length)
{
    int temp[small_length][small_length];
    for (int i = 0; i < small_length; i++)
    {
        for (int j = 0; j < small_length; j++)
        {
            temp[i][j] = A[startY + small_length - 1 - j][startX + i];
        }
    }
    for (int i = 0; i < small_length; i++)
    {
        for (int j = 0; j < small_length; j++)
        {
            A[startY + i][startX + j] = temp[i][j];
        }
    }
}

void firestorm(int level)
{
    int small_length = 1<<level;
    for (int i = 1; i <= length; i += small_length)
    {
        for (int j = 1; j <= length; j += small_length)
        {
            rotateBoard(i, j, small_length);
        }
    }

    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            A_copy[i][j] = A[i][j];

            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nextY = i + dy[k];
                int nextX = j + dx[k];
                if (nextY < 1 || nextY > length || nextX < 1 || nextX > length)
                {
                    continue;
                }
                if (A[nextY][nextX] != 0)
                {
                    cnt++;
                }
            }

            if (cnt < 3)
            {
                if (A[i][j] - 1 >= 0)
                {
                    A_copy[i][j] = A[i][j] - 1;
                }
                else
                {
                    A_copy[i][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            A[i][j] = A_copy[i][j];
        }
    }
}

int bfs(int startY, int startX)
{
    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;

    int cnt = 0;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 1 || nextY > length || nextX < 1 || nextX > length)
            {
                continue;
            }
            if (!visited[nextY][nextX] && A[nextY][nextX] != 0)
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &N, &Q);
    length = 1<<N;
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int level;
        scanf("%d", &level);
        firestorm(level);
    }

    int total = 0;
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            total += A[i][j];
        }
    }
    
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            visited[i][j] = false;
        }
    }

    int maximum = 0;
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            if (!visited[i][j] && A[i][j] != 0)
            {
                int result = bfs(i, j);
                if (result != 1)
                {
                    maximum = max(maximum, result);
                }
            }
        }
    }

    printf("%d\n", total);
    printf("%d\n", maximum);
    return 0;
}