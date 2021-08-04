#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define MAX 100001
#define LIMIT 18

using namespace std;

int N, M;
vector<int> tree[MAX];

int parent[MAX][LIMIT];
int depth[MAX];
bool visited[MAX] = {
    false,
};

void dfs(int n, int dep)
{
    visited[n] = true;
    depth[n] = dep;

    for (int i = 0; i < tree[n].size(); i++)
    {
        int next = tree[n][i];
        if (!visited[next])
        {
            parent[next][0] = n;
            dfs(next, dep + 1);
        }
    }
}

int LCA(int num1, int num2)
{
    if (depth[num1] < depth[num2])
    {
        swap(num1, num2);
    }

    if (depth[num1] != depth[num2])
    {
        for (int i = LIMIT - 1; i >= 0; i--)
        {
            if (depth[num1] - depth[num2] >= (1 << i))
            {
                num1 = parent[num1][i];
            }
        }
    }

    if (num1 == num2)
    {
        return num1;
    }

    for (int i = LIMIT - 1; i >= 0; i--)
    {
        if (parent[num1][i] != parent[num2][i])
        {
            num1 = parent[num1][i];
            num2 = parent[num2][i];
        }
    }

    return parent[num1][0];
}

int main()
{
    int v1, v2;

    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &v1, &v2);
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    dfs(1, 0);

    for (int j = 1; j < LIMIT; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    scanf("%d", &M);
    int num1, num2;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &num1, &num2);
        printf("%d\n", LCA(num1, num2));
    }

    return 0;
}