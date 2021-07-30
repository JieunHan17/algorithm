#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int T, N, M;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        int max = 0, cnt = 0;
        queue<pair<int, int> > q;
        priority_queue<pair<int, int> > pq;
        for (int j = 0; j < N; j++)
        {
            int num;
            scanf("%d", &num);
            q.push(make_pair(num, j));
            pq.push(make_pair(num, j));
        }

        while (1)
        {
            int cur = q.front().first;
            int curIdx = q.front().second;
            int max = pq.top().first;
            q.pop();
            if (cur == max)
            {
                pq.pop();
                cnt++;
                if (curIdx == M)
                {
                    break;
                }
            }
            else
            {
                q.push(make_pair(cur, curIdx));
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}