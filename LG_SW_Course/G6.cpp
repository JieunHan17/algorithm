#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAXN 10

using namespace std;

int N, M;
int s[100 + 10];
int e[100 + 10];
int in[MAXN + 10];
int num[MAXN + 10];

int parent[MAXN + 10];
vector<int> graph[MAXN + 10];
int indegree[MAXN + 10];
deque<int> dq; //순위별로 저장

void InputData()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> s[i] >> e[i];
        parent[e[i]] = s[i];
        graph[s[i]].push_back(e[i]);
        indegree[e[i]]++;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> in[i];
    }
}

bool isPossible()
{
    for (int i = 0; i < dq.size(); i++)
    {
        num[dq[i]] = in[i + 1];
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == 0)
        {
            continue;
        }
        if (num[i] >= num[parent[i]])
        {
            return false;
        }
    }
    return true;
}

bool DFS(int cur, int depth)
{
    cout << "cur: " << cur << " depth: " << depth << "\n";
    if (depth == N)
    {
        cout << "finish\n";
        if (isPossible())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for (int i = 0; i < graph[cur].size(); i++)
    {
        indegree[graph[cur][i]]--;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            indegree[i] = -1;
        }
    }

    while (!q.empty())
    {
        int next = q.front();
        dq.push_back(next);
        if (DFS(next, depth + 1))
        {
            return true;
        }
        q.pop();
        indegree[next] = 0;
        for (int i = 0; i < graph[next].size(); i++)
        {
            indegree[graph[cur][i]]++;
        }
        dq.pop_back();
    }

    return false;
}

void OutputData()
{
    for (int i = 1; i <= N; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}

int main()
{
    InputData(); //입력받는 부분

    // 여기서부터 작성
    sort(in + 1, in + N + 1, greater<int>());

    indegree[1] = -1;
    dq.push_back(1);
    DFS(1, 1);

    OutputData(); // 출력하는 부분
    return 0;
}