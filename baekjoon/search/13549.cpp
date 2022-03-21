#include <cstdio>
#include <deque>
#include <algorithm>

#define MAX 100001

using namespace std;

int dist[MAX];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    fill(dist, dist + MAX, -1);

    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;

    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        int next;

        // case 1
        next = cur * 2;
        if (next < MAX && dist[next] == -1)
        {
            dist[next] = dist[cur];
            dq.push_front(next);
        }

        // case 2
        next = cur - 1;
        if (next >= 0 && dist[next] == -1)
        {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }

        // case 3
        next = cur + 1;
        if (next < MAX && dist[next] == -1)
        {
            dist[next] = dist[cur] + 1;
            dq.push_back(next);
        }
    }

    printf("%d", dist[K]);

    return 0;
}