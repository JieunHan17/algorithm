#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int total = 0;

void prim(int start, bool visited[], vector<pair<int, int> > vertices[])
{
    priority_queue<pair<int, int> > pq;
    int size = vertices[start].size();
    for (int i = 0; i < size; i++)
    {
        int next = vertices[start][i].first;
        int weight = vertices[start][i].second;
        pq.push(make_pair(-weight, next));
    }

    visited[start] = true;
    while (pq.empty() == 0)
    {
        int weight = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (!visited[cur])
        {
            visited[cur] = true;
            total += weight;
            int size = vertices[cur].size();
            for (int i = 0; i < size; i++)
            {
                int next = vertices[cur][i].first;
                int weight = vertices[cur][i].second;
                if (!visited[next])
                {
                    pq.push(make_pair(-weight, next));
                }
            }
        }
    }
}

// 아래는 직전에 선택한 정점에 인접한 간선만 생각해줘서 틀림
/*
void prim(int curVertex, int V, int E, bool visited[], vector<pair<int, int> > vertices[])
{
printf("here!\n");
if (cnt == V - 1)
{
    return;
}

visited[curVertex] = true;
int size = vertices[curVertex].size();
for (int i = 0; i < size; i++)
{
    int nextVertex = vertices[curVertex][i].first;
    if (!visited[nextVertex])
    {
        cnt++;
        total += vertices[curVertex][i].second;
        printf("cnt: %d, total: %d\n", cnt, total);
        prim(nextVertex, V, E, visited, vertices);
        break;
    }
}
return;
}
*/

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    bool visited[V + 1];
    fill(visited, visited + V + 1, false);

    vector<pair<int, int> > vertices[V + 1];
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        vertices[A].push_back(make_pair(B, C));
        vertices[B].push_back(make_pair(A, C));
    }

    prim(1, visited, vertices);

    printf("%d", total);

    return 0;
}