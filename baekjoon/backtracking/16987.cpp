#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 9

using namespace std;

int N;
vector<pair<int, int> > v;
bool isBroken[MAX];
int ans = 0;

void func(int cur, int cnt)
{
    if (cur == N)
    {
        ans = max(ans, cnt);
        return;
    }

    if (isBroken[cur])
    {
        func(cur + 1, cnt);
        return;
    }
    
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        int nextCnt = cnt;
        if (!isBroken[i] && i != cur)
        {
            flag = true;
            int curS = v[cur].first;
            int curW = v[cur].second;

            int targetS = v[i].first;
            int targetW = v[i].second;

            v[cur].first -= targetW;
            v[i].first -= curW;
            if (targetS - curW <= 0)
            {
                isBroken[i] = true;
                nextCnt++;
            }
            if (curS - targetW <= 0)
            {
                isBroken[cur] = true;
                nextCnt++;
            }

            func(cur + 1, nextCnt);

            v[cur].first += targetW;
            v[i].first += curW;
            isBroken[i] = false;
            isBroken[cur] = false;
        }
    }
    if (!flag)
    {
        func(cur + 1, cnt);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int s, w;
        scanf("%d %d", &s, &w);
        v.push_back(make_pair(s, w));
    }

    func(0, 0);
    printf("%d", ans);
    return 0;
}