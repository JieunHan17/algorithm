#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 10001

using namespace std;

vector<pair<int, int> > v[MAX];
bool visited[MAX] = {
    false,
};
int maximum = 0;

int dfs(int start, int total)
{
    visited[start] = true;
    bool flag = false;
    for (int i = 0; i < v[start].size(); i++)
    {
        int next = v[start][i].first;
        int weight = v[start][i].second;
        if (!visited[next])
        {
            flag = true;
            dfs(next, total + weight);
        }
    }
    if (!flag)
    {
        maximum = max(maximum, total);
    }

    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    for (int i = 1; i <= N; i++)
    {
        fill(visited, visited + N + 1, false);
        dfs(i, 0);
    }

    printf("%d\n", maximum);
    return 0;
}
