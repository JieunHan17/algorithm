#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

int dfs(int start, vector<int> a[], bool visited[])
{
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < a[start].size(); i++)
    {
        int next = a[start][i];
        if (visited[next] == false)
        {
            dfs(next, a, visited);
        }
    }
    return 0;
}

int bfs(int start, vector<int> a[], bool visited[])
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int front = q.front();
        printf("%d ", front);
        q.pop();

        for (int i = 0; i < a[front].size(); i++)
        {
            if (visited[a[front][i]] == false)
            {
                q.push(a[front][i]);
                visited[a[front][i]] = true;
            }
        }
    }

    return 0;
}

int main()
{
    int u = 0, v = 0;
    bool visited[1001];

    scanf("%d %d %d", &N, &M, &V);

    vector<int> a[N + 1];

    fill(visited, visited + (N + 1), false);

    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(a[i].begin(), a[i].end());
    }

    dfs(V, a, visited);
    printf("\n");
    fill(visited, visited + (N + 1), false);
    bfs(V, a, visited);

    return 0;
}