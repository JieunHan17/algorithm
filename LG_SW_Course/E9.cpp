#include <iostream>
#include <algorithm>
#include <vector>
 
#define MAXN 11
#define LIMIT 98765
 
using namespace std;
 
int n;
int cost[MAXN][MAXN];
int combi[MAXN];
int sol[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }
     
    vector<int> v;
    for (int i = 1; i <= n; i++) 
    {
        v.push_back(i);
    }
     
    int minimum = LIMIT;
    do {
        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            total += cost[i][v[i - 1]];
        }
        if (minimum > total)
        {
            minimum = total;
            for (int i = 1; i <= n; i++)
            {
                sol[i] = v[i - 1];
            }
        }
    } while (next_permutation(v.begin(), v.end()));
 
    cout << minimum << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << sol[i] << " ";
    }
    return 0;
}

/* DFS 구현 */
/*
bool visited[MAXN];
int ans = LIMIT;

void DFS(int cnt, int total)
{
    if (cnt == n)
    {
        if (total < ans)
        {
            ans = total;
            for (int i = 1; i <= n; i++)
            {
                sol[i] = combi[i];
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            combi[cnt + 1] = i;
            DFS(cnt + 1, total + cost[cnt + 1][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }

    DFS(0, 0);

    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << sol[i] << " ";
    }
    return 0;
}
*/