#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int m[MAX][MAX];
int m_copy[MAX][MAX];
int dy[4] = {0, -1, 0, 1}; //동북서남
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int> > v_virus;
vector<pair<int, int> > v_empty;

void bfs()
{
    queue<pair<int, int> > q;
    bool visited[MAX][MAX] = {false,};
    for (int i = 0; i < v_virus.size(); i++)
    {
        q.push(make_pair(v_virus[i].first, v_virus[i].second));
        visited[v_virus[i].first][v_virus[i].second] = true;
    }

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
            {
                continue;
            }
            if (!visited[nextY][nextX] && m_copy[nextY][nextX] == 0)
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
                m_copy[nextY][nextX] = 2;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 2)
            {
                v_virus.push_back(make_pair(i, j));
            }
            else if (m[i][j] == 0)
            {
                v_empty.push_back(make_pair(i, j));
            }
        }
    }

    vector<int> v;
    for (int i = 0; i < 3; i++)
    {
        v.push_back(0);
    }
    for (int i = 3; i < v_empty.size(); i++)
    {
        v.push_back(1);
    }

    int ans = 0;
    do
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                m_copy[i][j] = m[i][j];
            }
        }
        
        for (int i = 0; i < v_empty.size(); i++)
        {
            if (v[i] == 0)
            {
                m_copy[v_empty[i].first][v_empty[i].second] = 1;
            }
        }

        bfs();

        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (m_copy[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    } while (next_permutation(v.begin(), v.end()));
    
    printf("%d", ans);
    return 0;
}