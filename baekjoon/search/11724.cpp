#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int bfs(vector<int> node[])
{
    int cnt = 0;
    bool visited[N + 1];

    fill(visited, visited + (N + 1), false);

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int i = 0; i < node[cur].size(); i++)
                {
                    int next = node[cur][i];
                    if (!visited[next])
                    {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int u, v;

    scanf("%d %d", &N, &M);

    vector<int> node[N + 1];

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        node[u].push_back(v);
        node[v].push_back(u);
    }

    printf("%d\n", bfs(node));
    return 0;
}