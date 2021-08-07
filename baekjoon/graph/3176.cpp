#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define MAX 100001
#define LIMIT 18 //10^5 < 2^17
#define INF 987654321

using namespace std;

int n, k;
vector<pair<int, int> > network[MAX];

int parent[MAX][LIMIT];
int dep[MAX];
int maxLen[MAX][LIMIT];
int minLen[MAX][LIMIT];
bool visited[MAX] = {
    false,
};

void dfs(int start, int depth)
{
    visited[start] = true;
    dep[start] = depth;

    for (int i = 0; i < network[start].size(); i++)
    {
        int next = network[start][i].first;
        int length = network[start][i].second;

        if (!visited[next])
        {
            parent[next][0] = start;
            minLen[next][0] = length;
            maxLen[next][0] = length;
            dfs(next, depth + 1);
        }
    }
}

pair<int, int> lca(int num1, int num2)
{
    int minimum = INF;
    int maximum = -1;

    if (dep[num1] < dep[num2])
    {
        swap(num1, num2);
    }

    if (dep[num1] != dep[num2])
    {
        for (int i = LIMIT - 1; i >= 0; i--)
        {
            if (dep[num1] - dep[num2] >= (1 << i))
            {
                minimum = min(minimum, minLen[num1][i]);
                maximum = max(maximum, maxLen[num1][i]);
                num1 = parent[num1][i];
            }
        }
    }

    if (num1 == num2)
    {
        return make_pair(minimum, maximum);
    }

    for (int i = LIMIT - 1; i >= 0; i--)
    {
        if (parent[num1][i] != parent[num2][i])
        {
            minimum = min(minimum, min(minLen[num1][i], minLen[num2][i]));
            maximum = max(maximum, max(maxLen[num1][i], maxLen[num2][i]));
            num1 = parent[num1][i];
            num2 = parent[num2][i];
        }
    }

    minimum = min(minimum, min(minLen[num1][0], minLen[num2][0]));
    maximum = max(maximum, max(maxLen[num1][0], maxLen[num2][0]));

    return make_pair(minimum, maximum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        network[a].push_back(make_pair(b, c));
        network[b].push_back(make_pair(a, c));
    }

    dfs(1, 0);

    for (int j = 1; j < LIMIT; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            maxLen[i][j] = max(maxLen[i][j - 1], maxLen[parent[i][j - 1]][j - 1]);
            minLen[i][j] = min(minLen[i][j - 1], minLen[parent[i][j - 1]][j - 1]);
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int d, e;
        scanf("%d %d", &d, &e);

        pair<int, int> answer = lca(d, e);
        printf("%d %d\n", answer.first, answer.second);
    }

    return 0;
}

/*
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define MAX 100001
#define LIMIT 18
#define INF 987654321

using namespace std;

int n, k;
vector<pair<int, int> > network[MAX];

int parent[MAX][LIMIT];
int dep[MAX];
int maxLen[MAX][LIMIT] = {
    0,
};
int minLen[MAX][LIMIT] = {
    0,
};
bool visited[MAX] = {
    false,
};

void dfs(int start, int depth)
{
    visited[start] = true;
    dep[start] = depth;

    for (int i = 0; i < network[start].size(); i++)
    {
        int next = network[start][i].first;
        int length = network[start][i].second;

        if (!visited[next])
        {
            parent[next][0] = start;
            minLen[next][0] = length;
            maxLen[next][0] = length;
            dfs(next, depth + 1);
        }
    }
}

int lca(int num1, int num2)
{
    if (dep[num1] < dep[num2])
    {
        swap(num1, num2);
    }

    if (dep[num1] != dep[num2])
    {
        for (int i = LIMIT - 1; i >= 0; i--)
        {
            if (dep[num1] - dep[num2] >= (1 << i))
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
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        network[a].push_back(make_pair(b, c));
        network[b].push_back(make_pair(a, c));
    }

    dfs(1, 0);

    for (int j = 1; j < LIMIT; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            maxLen[i][j] = max(maxLen[i][j - 1], maxLen[parent[i][j - 1]][j - 1]);
            minLen[i][j] = min(minLen[i][j - 1], minLen[parent[i][j - 1]][j - 1]);
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int d, e;
        scanf("%d %d", &d, &e);

        int ancestor = lca(d, e);
        int ans_min = INF, ans_max = -1;
        for (int i = LIMIT - 1; i >= 0; i--)
        {
            if (dep[d] - dep[ancestor] >= (1 << i))
            {
                ans_min = min(ans_min, minLen[d][i]);
                ans_max = max(ans_max, maxLen[d][i]);
                d = parent[d][i];
            }
        }
        for (int i = LIMIT - 1; i >= 0; i--)
        {
            if (dep[e] - dep[ancestor] >= (1 << i))
            {
                ans_min = min(ans_min, minLen[e][i]);
                ans_max = max(ans_max, maxLen[e][i]);
                e = parent[e][i];
            }
        }
        printf("%d %d\n", ans_min, ans_max);
    }

    return 0;
}
*/
