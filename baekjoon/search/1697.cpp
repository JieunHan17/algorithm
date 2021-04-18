#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int N, int K, bool visited[])
{
    queue<pair<int, int> > q;

    q.push(make_pair(N, 0));
    visited[N] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur == K)
        {
            return time;
        }

        int next;

        next = cur - 1;
        if (0 <= next && next <= 100000 && !visited[next])
        {
            q.push(make_pair(next, time + 1));
            visited[next] = true;
        }

        next = cur + 1;
        if (0 <= next && next <= 100000 && !visited[next])
        {
            q.push(make_pair(next, time + 1));
            visited[next] = true;
        }

        next = cur * 2;
        if (0 <= next && next <= 100000 && !visited[next])
        {
            q.push(make_pair(next, time + 1));
            visited[next] = true;
        }
    }

    return 0;
}

int main()
{
    bool visited[100001] = {
        false,
    };

    int N, K;

    scanf("%d %d", &N, &K);

    printf("%d", bfs(N, K, visited));

    return 0;
}