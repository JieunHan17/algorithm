#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define MAX 100001

using namespace std;

vector<int> node[MAX];
int parent[MAX];
bool visited[MAX] = {
    false,
};

void bfs(int start, int N)
{
    queue<pair<int, int> > q;
    int cur_parent = start;
    q.push(make_pair(start, cur_parent));
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        parent[cur] = q.front().second;
        q.pop();

        for (int i = 0; i < node[cur].size(); i++)
        {
            int next = node[cur][i];
            if (!visited[next])
            {
                q.push(make_pair(next, cur));
                visited[next] = true;
            }
        }
    }

    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }

    bfs(1, N);

    for (int i = 2; i <= N; i++)
    {
        printf("%d\n", parent[i]);
    }
    return 0;
}