#include <iostream>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

#define MAXN (100)
#define MAX 987654321

int L;//정비를 받지 않고 갈수있는 최대거리
int N;//정비소 개수
int dist[MAXN+10];//정비소사이거리
int times[MAXN+10];//정비시간
int visited[MAXN+10];
int path[MAXN+10];

void InputData(){
    cin >> L;
    cin >> N;
    for (int i=1; i<=N+1; i++){
        cin >> dist[i];
    }
    for (int i=1; i<=N; i++){
        cin >> times[i];
    }
}

void Initialize()
{
    for (int i = 1; i <= N + 1; i++)
    {
        visited[i] = MAX;
        path[i] = -2;
    }
}

vector<int> GetNext(int curIdx)
{
    vector<int> v;
    for (int i = curIdx + 1; i <= N + 1; i++)
    {
        int sum = 0;
        for (int j = curIdx + 1; j <= i; j++)
        {
            sum += dist[j];
        }
        if (sum <= L)
        {
            v.push_back(i);
        }
    }
    return v;
}

int BFS()
{
    Initialize();

    queue<int> q;
    q.push(0);
    visited[0] = 0;
    path[0] = -1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        vector<int> next = GetNext(cur);
        for (int i = 0; i < next.size(); i++)
        {
            if (visited[next[i]] > visited[cur] + times[next[i]])
            {
                q.push(next[i]);
                visited[next[i]] = visited[cur] + times[next[i]];
                path[next[i]] = cur;
            }
        }
    }
    return visited[N + 1];
}

int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    int ans = BFS();
    cout << ans << "\n";

    int curPath = path[N + 1];
    stack<int> s;
    while (1)
    {
        if (path[curPath] == -1)
        {
            break;
        }
        s.push(curPath);
        curPath = path[curPath];
    }
    
    if (!s.empty())
    {
        cout << s.size() << "\n";
    }
    
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}