#include <cstdio>
#include <algorithm>

#define MAX 101
#define INF 987654321

using namespace std;

int n, m;
int d[MAX][MAX] = {
    INF,
};

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
            if (i == j)
            {
                d[i][j] = 0;
            }
        }
    }

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (d[a][b] > c)
        {
            d[a][b] = c;
        }
    }

    floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ", d[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}