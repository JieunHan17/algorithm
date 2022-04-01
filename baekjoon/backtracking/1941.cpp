#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

string students[6];
bool visited[6][6];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int ans = 0;

bool bfs(vector<pair<int, int> > v)
{
    int temp[6][6];
    for (int i = 0; i < 5; i++)
    {
        fill(temp[i], temp[i] + 5, 0);
        fill(visited[i], visited[i] + 5, false);
    }

    for (int i = 0; i < 7; i++)
    {
        temp[v[i].first][v[i].second] = 1;
    }

    queue<pair<int, int> > q;
    q.push(v[0]);
    visited[v[0].first][v[0].second] = true;

    int cnt = 0;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= 5 || nextX < 0 || nextX >= 5)
            {
                continue;
            }
            if (!visited[nextY][nextX] && temp[nextY][nextX])
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }

    if (cnt == 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        cin >> students[i];
    }

    vector<int> arr;
    for (int i = 0; i < 7; i++)
    {
        arr.push_back(0);
    }
    for (int i = 7; i < 25; i++)
    {
        arr.push_back(1);
    }

    do
    {
        int cnt = 0;
        vector<pair<int, int> > v;
        for (int i = 0; i < 25; i++)
        {
            if (!arr[i])
            {
                int row = i / 5;
                int col = i % 5;
                v.push_back(make_pair(row, col));
                if (students[row][col] == 'S')
                {
                    cnt++;
                }
            }
        }
        if (cnt >= 4 && bfs(v))
        {
            ans++;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    

    printf("%d", ans);
    return 0;
}