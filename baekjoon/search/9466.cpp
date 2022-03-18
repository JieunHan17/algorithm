#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 100001

using namespace std;

int choices[MAX];
int visited[MAX];

void search(int n, int start)
{
    int cur = start;
    while (1)
    {
        visited[cur] = start;
        cur = choices[cur];

        if (visited[cur] == start)
        {
            while (visited[cur] != -1)
            {
                visited[cur] = -1;
                cur = choices[cur];
            }
            return;
        }
        else if (visited[cur] != 0)
        {
            return;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        fill(visited + 1, visited + n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &choices[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                search(n, i);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] != -1)
            {
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}