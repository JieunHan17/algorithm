#include <cstdio>
#include <vector>

#define MAX 501
#define INF 987654321

using namespace std;

int n, m;
long long d[MAX];
vector<pair<pair<int, int>, int> > edge;

bool BellmanFord(int start)
{
    d[start] = 0;
    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < edge.size(); j++)
        {
            int depart = edge[j].first.first;
            int arrive = edge[j].first.second;
            int cost = edge[j].second;

            if (d[depart] == INF)
            {
                continue;
            }

            if (d[arrive] > d[depart] + cost)
            {
                if (i == n)
                {
                    isCycle = true;
                }
                d[arrive] = d[depart] + cost;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INF)
        {
            d[i] = -1;
        }
    }
    return isCycle;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back(make_pair(make_pair(a, b), c));
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    bool isCycle = BellmanFord(1);
    if (isCycle)
    {
        printf("%d", -1);
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            printf("%lld\n", d[i]);
        }
    }

    return 0;
}