#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAXN 100
#define INF 10000000000

using namespace std;

int N, M;
int A[10000 + 10];
int B[10000 + 10];
int L[10000 + 10];
vector<int> path[MAXN + 10]; //도착지
int dist[MAXN + 10][MAXN + 10];
long long visited[MAXN + 10];

void InputData(){
    cin >> N >> M;
    for (int i = 0; i<M; i++){
        cin >> A[i] >> B[i] >> L[i];
        path[A[i]].push_back(B[i]);
        path[B[i]].push_back(A[i]);
        dist[A[i]][B[i]] = L[i];
        dist[B[i]][A[i]] = L[i];
    }
}

void Initialize()
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = INF;
    }
}

long long BFS()
{
    Initialize();

    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < path[cur].size(); i++)
        {
            int next = path[cur][i];
            int len = dist[cur][next];

            if (visited[next] > visited[cur] + len)
            {
                q.push(next);
                visited[next] = visited[cur] + len;
            }
        }
    }

    return visited[N];
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    long long originDist = BFS();
    long long newDist = originDist;
    for (int i = 0; i < M; i++)
    {
        dist[A[i]][B[i]] *= 2;
        dist[B[i]][A[i]] *= 2;
        newDist = max(newDist, BFS());
        dist[A[i]][B[i]] /= 2;
        dist[B[i]][A[i]] /= 2;
    }

    ans = newDist - originDist;

    cout << ans << endl;// 출력하는 부분
    return 0;
}