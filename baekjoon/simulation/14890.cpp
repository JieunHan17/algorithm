#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX_N 101

using namespace std;

int N, L;
int m[MAX_N][MAX_N];
bool temp[MAX_N];
int ans = 0;

bool func(int row, int col)
{
    int cur = m[row][col - 1];
    for (int i = 1; i <= L; i++)
    {
        if (col - i < 0)
        {
            return false;
        }
        if (cur != m[row][col - i])
        {
            return false;
        }
        if (temp[col - i])
        {
            return false;
        }
        temp[col - i] = true;
    }
    return true;
}

bool func2(int row, int col)
{
    int cur = m[row][col + 1];
    for (int i = 1; i <= L; i++)
    {
        if (col + i >= N)
        {
            return false;
        }
        if (cur != m[row][col + i])
        {
            return false;
        }
        if (temp[col + i])
        {
            return false;
        }
        temp[col + i] = true;
    }
    return true;
}

bool func3(int row, int col)
{
    int cur = m[row - 1][col];
    for (int i = 1; i <= L; i++)
    {
        if (row - i < 0)
        {
            return false;
        }
        if (cur != m[row - i][col])
        {
            return false;
        }
        if (temp[row - i])
        {
            return false;
        }
        temp[row - i] = true;
    }
    return true;
}

bool func4(int row, int col)
{
    int cur = m[row + 1][col];
    for (int i = 1; i <= L; i++)
    {
        if (row + i >= N)
        {
            return false;
        }
        if (cur != m[row + i][col])
        {
            return false;
        }
        if (temp[row + i])
        {
            return false;
        }
        temp[row + i] = true;
    }
    return true;
}

int main()
{
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        fill(temp, temp + N, false);
        bool isAble = true;
        for (int j = 0; j < N - 1; j++)
        {
            if (m[i][j] != m[i][j + 1])
            {
                if (m[i][j + 1] == m[i][j] + 1)
                {
                    if (!func(i, j + 1))
                    {
                        isAble = false;
                        break;
                    }
                }
                else if (m[i][j] == m[i][j + 1] + 1)
                {
                    if (!func2(i, j))
                    {
                        isAble = false;
                        break;
                    }
                }
                else
                {
                    isAble = false;
                    break;
                }
            }
        }
        if (isAble)
        {
            ans++;
        }
    }

    for (int j = 0; j < N; j++)
    {
        fill(temp, temp + N, false);
        bool isAble = true;
        for (int i = 0; i < N - 1; i++)
        {
            if (m[i][j] != m[i + 1][j])
            {
                if (m[i + 1][j] == m[i][j] + 1)
                {
                    if (!func3(i + 1, j))
                    {
                        isAble = false;
                        break;
                    }
                }
                else if (m[i][j] == m[i + 1][j] + 1)
                {
                    if (!func4(i, j))
                    {
                        isAble = false;
                        break;
                    }
                }
                else
                {
                    isAble = false;
                    break;
                }
            }
        }
        if (isAble)
        {
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}

// 시간 복잡도: 100 * 100 * 10 = 100,000