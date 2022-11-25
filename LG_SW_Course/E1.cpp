#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAX 150
#define INF 98765432

using namespace std;

int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];
char farm;
int sol;
vector<pair<int, int> > path[MAX]; //(도착지, 길이)
int visited[MAX];
int departure[MAX];

void InputData(){
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> N1[i] >> N2[i] >> L[i];
        path[N1[i]].push_back(make_pair(N2[i], L[i]));
        path[N2[i]].push_back(make_pair(N1[i], L[i]));
    }
}

void Initialize()
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = INF;
        departure[i] = -1;
    }
}

int BFS()
{
    queue<int> q;
    for (int i = 0; i < P; i++)
    {
        if (N1[i] >= 'A' && N1[i] <= 'Y')
        {
            q.push(N1[i]);
            visited[N1[i]] = 0;
            departure[N1[i]] = 0;
        }
        else if (N2[i] >= 'A' && N2[i] <= 'Y')
        {
            q.push(N2[i]);
            visited[N2[i]] = 0;
            departure[N2[i]] = 0;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < path[cur].size(); i++)
        {
            int next = path[cur][i].first;
            int cost = path[cur][i].second;

            if (visited[next] > visited[cur] + cost)
            {
                q.push(next);
                visited[next] = visited[cur] + cost;
                departure[next] = cur;
            }
        }
    }
    return visited['Z'];
}

int main(){
    InputData();// 입력받는 부분
    
    // 여기서부터 작성
    Initialize();
    sol = BFS();
    
    farm = 'Z';
    while (1)
    {
        if (departure[farm] == 0)
        {
            break;
        }
        farm = departure[farm];
    }

    cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}