#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define MAX 20001
#define INF 987654321

using namespace std;

int V, E, K;
int dist[MAX];
vector<pair<int, int> > graph[MAX];

struct compare
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
    pq.push(make_pair(K, 0));
    dist[K] = 0;

    while (!pq.empty())
    {
        int curPos = pq.top().first;
        int curCost = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[curPos].size(); i++)
        {
            int nextPos = graph[curPos][i].first;
            int nextCost = graph[curPos][i].second;
            if (dist[nextPos] > curCost + nextCost)
            {
                dist[nextPos] = curCost + nextCost;
                pq.push(make_pair(nextPos, dist[nextPos]));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
    }
}

int main()
{
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= V; i++)
    {
        dist[i] = INF;
    }

    dijkstra();
    return 0;
}