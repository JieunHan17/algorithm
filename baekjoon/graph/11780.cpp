#include <cstdio>
#include <queue>

#define MAX 101
#define INF 9876543

using namespace std;

int n, m;
int dist[MAX][MAX];
int check[MAX][MAX];
queue<int> q[MAX * MAX];

void checkPath(int row, int col, int index)
{
    if (check[row][col] == 0)
    {
        return;
    }
    checkPath(row, check[row][col], index);
    q[index].push(check[row][col]);
    checkPath(check[row][col], col, index);
}

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    check[i][j] = k;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (dist[a][b] > c)
        {
            dist[a][b] = c;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            check[i][j] = 0;
        }
    }

    floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                dist[i][j] = 0;
            }
            if (dist[i][j] != 0)
            {
                int index = (i - 1) * n + j;
                q[index].push(i);
                checkPath(i, j, index);
                q[index].push(j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int index = (i - 1) * n + j;
            if (q[index].empty())
            {
                printf("0 ");
            }
            else
            {
                printf("%lu ", q[index].size());
                while (!q[index].empty())
                {
                    printf("%d ", q[index].front());
                    q[index].pop();
                }
            }
            printf("\n");
        }
    }

    return 0;
}