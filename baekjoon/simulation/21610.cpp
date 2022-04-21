#include <cstdio>
#include <utility>

#define MAX_N 51

using namespace std;

int N, M;
int A[MAX_N][MAX_N];
bool cloud[MAX_N][MAX_N];
bool cloud_save[MAX_N][MAX_N];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
pair<int, int> diagonal[4] = {make_pair(-1, -1), make_pair(-1, 1), make_pair(1, 1), make_pair(1, -1)};

int check(int num)
{
    if (num == 0)
    {
        return N;
    }
    else if (num == N + 1)
    {
        return 1;
    }
    else
    {
        return num;
    }
}

void first(int d, int s)
{
    for (int k = 0; k < s; k++)
    {
        bool cloud_copy[MAX_N][MAX_N] = {false, };
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (cloud[i][j])
                {
                    int nextY = check(i + dy[d - 1]);
                    int nextX = check(j + dx[d - 1]);
                    cloud_copy[nextY][nextX] = true;
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cloud[i][j] = cloud_copy[i][j];
            }
        }
    }
}

void second()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (cloud[i][j])
            {
                A[i][j]++;
            }
        }
    }
}

void third()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cloud_save[i][j] = cloud[i][j];
            if (cloud[i][j])
            {
                cloud[i][j] = false;
            }
        }
    }
}

void fourth()
{
    int A_copy[MAX_N][MAX_N] = {0, };
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            A_copy[i][j] = A[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (cloud_save[i][j])
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nextY = i + diagonal[k].first;
                    int nextX = j + diagonal[k].second;
                    if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
                    {
                        continue;
                    }
                    if (A[nextY][nextX] > 0)
                    {
                        cnt++;
                    }
                }
                A_copy[i][j] += cnt;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            A[i][j] = A_copy[i][j];
        }
    }
}

void fifth()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (A[i][j] >= 2 && !cloud_save[i][j])
            {
                A[i][j] -= 2;
                cloud[i][j] = true;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    cloud[N][1] = true;
    cloud[N][2] = true;
    cloud[N - 1][1] = true;
    cloud[N - 1][2] = true;

    while (M--)
    {
        int d, s;
        scanf("%d %d", &d, &s);
        
        first(d, s);
        second();
        third();
        fourth();
        fifth();
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ans += A[i][j];
        }
    }
    printf("%d", ans);
    return 0;
}