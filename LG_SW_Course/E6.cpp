#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN (50)

int N, M, K;//철도역수, 철도수, 추가로 연결시킬수있는 철도수
int S[MAXN + 10];
int E[MAXN + 10];
vector<int> path[MAXN + 10];
int visited[MAXN + 10];
vector<pair<int, int> > v; // (연결되어 있는 도시의 수, 그룹 인덱스)

void InputData() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> E[i];
        path[S[i]].push_back(E[i]);
        path[E[i]].push_back(S[i]);
    }
}

int BFS(int start, int idx)
{
    queue<int> q;
    q.push(start);
    visited[start] = idx;

    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < path[cur].size(); i++)
        {
            int next = path[cur][i];

            if (visited[next] > 0)
            {
                continue;
            }
            q.push(next);
            visited[next] = idx;
        }
    }
    return cnt;
}

bool compare(pair<int, int> input1, pair<int, int> input2)
{
    return input1.first > input2.first;
}

int main() {
    InputData();//입력받는 부분

	// 여기서부터 작성
    int idx = 1;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            int cnt = BFS(i, idx);
            v.push_back(make_pair(cnt, idx));
            idx++;
        }
    }

    sort(v.begin(), v.end(), compare);

    int ans = v[0].first;
    int i = 1;
    while (K--)
    {
        ans += v[i].first;
        i++;
    }
	
    cout << ans << "\n";// 출력하는 부분
    return 0;
}