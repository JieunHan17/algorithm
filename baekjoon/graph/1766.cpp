#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 32001

using namespace std;

int n, m;
vector<int> graph[MAX];

void TopologicalSort(int degree[])
{
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            pq.push(i);
        }
    }

    bool visited[n];
    fill(visited, visited + n, false);

    while (!pq.empty())
    {
        int cur = pq.top();
        printf("%d ", cur);
        visited[cur] = true;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            degree[next]--;
            if (!visited[next] && degree[next] == 0)
            {
                pq.push(next);
            }
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &n, &m);
    int degree[n + 1];
    fill(degree, degree + n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int earlier, later;
        scanf("%d %d", &earlier, &later);
        degree[later]++;
        graph[earlier].push_back(later);
    }

    TopologicalSort(degree);

    return 0;
}