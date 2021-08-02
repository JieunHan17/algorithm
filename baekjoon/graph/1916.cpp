#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

#define MAX 1001
#define INF 987654321

using namespace std;

int N, M;
int d[MAX];
vector<pair<int, int> > graph[MAX];

void dijkstra(int start, int d[])
{
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty())
    {
        int curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (d[curNode] < curWeight)
        {
            continue;
        }

        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int nextWeight = graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;
            int nextDist = curWeight + nextWeight;

            if (d[nextNode] > nextDist)
            {
                d[nextNode] = nextDist;
                pq.push(make_pair(-nextDist, nextNode));
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int node1, node2, weight;
        scanf("%d %d %d", &node1, &node2, &weight);
        graph[node1].push_back(make_pair(node2, weight));
    }

    int start, end;
    scanf("%d %d", &start, &end);

    for (int i = 1; i <= N; i++)
    {
        d[i] = INF;
    }

    dijkstra(start, d);

    printf("%d\n", d[end]);

    return 0;
}