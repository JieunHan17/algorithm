#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

string field[12];
bool visited[12][7];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int puyo;

bool hit(int startY, int startX)
{
    int cnt = 1;
    vector<pair<int, int> > v;
    v.push_back(make_pair(startY, startX));
    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = true;

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= 12 || nextX < 0 || nextX >= 6)
            {
                continue;
            }
            if (!visited[nextY][nextX] && field[nextY][nextX] == field[curY][curX])
            {
                cnt++;
                v.push_back(make_pair(nextY, nextX));
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = true;
            }
        }
    }

    if (cnt >= 4)
    {
        puyo -= cnt;
        for (int i = 0; i < v.size(); i++)
        {
            field[v[i].first][v[i].second] = '.';
        }

        return true;
    }
    else
        return false;
}

void drop()
{
    for (int col = 0; col < 6; col++)
    {
        int idx = 11;
        for (int i = 11; i >= 0; i--)
        {
            if (field[i][col] != '.')
            {
                if (field[idx][col] == '.')
                {
                    field[idx][col] = field[i][col];
                    field[i][col] = '.';
                    idx--;
                }
                else
                {
                    idx--;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 12; i++)
    {
        cin >> field[i];
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (field[i][j] != '.')
            {
                puyo++;
            }
        }
    }

    int ans = 0;
    while (1)
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                visited[i][j] = false;
            }
        }

        bool flag = false;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (field[i][j] == '.' || visited[i][j])
                {
                    continue;
                }
                
                if (hit(i, j))
                {
                    flag = true;
                }    
            }
        }
        if (flag)
        {
            ans++;
        }
        else
        {
            break;
        }
            
        drop();
    }

    cout << ans;
    return 0;
}