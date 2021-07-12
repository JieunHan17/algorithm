#include <cstdio>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int n, m, input1, input2;
int indegree[MAX] = {
    0,
};
vector<int> input[MAX];

void topologicalSort()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (int j = 0; j < input[cur].size(); j++)
        {
            if (--indegree[input[cur][j]] == 0)
            {
                q.push(input[cur][j]);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &input1, &input2);
        input[input1].push_back(input2);
        indegree[input2]++;
    }

    topologicalSort();

    return 0;
}