#include <cstdio>
#include <utility>
#include <algorithm>

#define MAX 501
using namespace std;

int N, M;
int paper[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 0;

pair<int, int> remove_rc[2] = {make_pair(3, 2), make_pair(2, 3)};
pair<int, int> remove_pair[2][8][2] = {
    {
        {make_pair(0, 1), make_pair(1, 1)},
        {make_pair(0, 0), make_pair(1, 0)},
        {make_pair(1, 1), make_pair(2, 1)},
        {make_pair(1, 0), make_pair(2, 0)},
        {make_pair(0, 0), make_pair(2, 0)},
        {make_pair(0, 1), make_pair(2, 1)},
        {make_pair(2, 0), make_pair(0, 1)},
        {make_pair(0, 0), make_pair(2, 1)}
    },
    {
        {make_pair(0, 0), make_pair(0, 1)},
        {make_pair(0, 1), make_pair(0, 2)},
        {make_pair(1, 1), make_pair(1, 2)},
        {make_pair(1, 0), make_pair(1, 1)},
        {make_pair(0, 0), make_pair(0, 2)},
        {make_pair(1, 0), make_pair(1, 2)},
        {make_pair(0, 0), make_pair(1, 2)},
        {make_pair(1, 0), make_pair(0, 2)}
    },
    
};

void search1(int startY, int startX)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int curY = startY + i;
        int curX = startX;
        if (curY < 0 || curY >= N)
        {
            return;
        }
        sum += paper[curY][curX];
    }
    ans = max(ans, sum);
}

void search2(int startY, int startX)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int curY = startY;
        int curX = startX + i;
        if (curX < 0 || curX >= M)
        {
            return;
        }
        sum += paper[curY][curX];
    }
    ans = max(ans, sum);
}

void search3(int startY, int startX)
{
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int curY = startY + i;
            int curX = startX + j;
            if (curY < 0 || curY >= N || curX < 0 || curX >= M)
            {
                return;
            }
            sum += paper[curY][curX];
        }
    }
    ans = max(ans, sum);
}

void search4(int startY, int startX, int idx)
{
    int sum = 0;
    for (int i = 0; i < remove_rc[idx].first; i++)
    {
        for (int j = 0; j < remove_rc[idx].second; j++)
        {
            int curY = startY + i;
            int curX = startX + j;
            if (curY < 0 || curY >= N || curX < 0 || curX >= M)
            {
                return;
            }
            sum += paper[curY][curX];
        }
    }

    for (int i = 0; i < 8; i++)
    {
        int temp = sum;
        for (int j = 0; j < 2; j++)
        {
            int removeY = startY + remove_pair[idx][i][j].first;
            int removeX = startX + remove_pair[idx][i][j].second;
            temp -= paper[removeY][removeX];
        }
        ans = max(ans, temp);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            search1(i, j);
            search2(i, j);
            search3(i, j);
            search4(i, j, 0);
            search4(i, j, 1);
        }
    }
    
    printf("%d", ans);
    return 0;
}

// 시간 복잡도: 500 * 500 * 16 = 4,000,000