#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

vector<deque<int> > v;
pair<int, int> touch[4];
bool visited[4];

void rotate(int num, int dir)
{
    int idx = num - 1;
    visited[idx] = true;

    if (dir == 1)
    {
        v[idx].push_front(v[idx].back());
        v[idx].pop_back();
    }
    else if (dir == -1)
    {
        v[idx].push_back(v[idx].front());
        v[idx].pop_front();
    }

    if (num > 1)
    {
        if (!visited[idx - 1] && touch[idx].first != touch[idx - 1].second)
        {
            rotate(num - 1, dir * (-1));
        }
    }
    if (num < 4)
    {
        if (!visited[idx + 1] && touch[idx].second != touch[idx + 1].first)
        {
            rotate(num + 1, dir * (-1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++)
    {
        string input;
        cin >> input;
        
        deque<int> d;
        for (int j = 0; j < 8; j++)
        {
            d.push_back(input[j] - '0');
        }

        v.push_back(d);
    }

    int K;
    cin >> K;

    while (K--)
    {
        int num, dir;
        cin >> num >> dir;
        for (int i = 0; i < 4; i++)
        {
            touch[i].first = v[i][6]; // 9시 방향
            touch[i].second = v[i][2]; // 3시 방향
        }
        fill(visited, visited + 4, false);
        rotate(num, dir);
    }

    int ans = 0;
    int temp = 1;
    for (int i = 0; i < 4; i++)
    {
        if (v[i].front() == 1)
        {
            ans += temp;
        }
        temp *= 2;
    }

    cout << ans;
    return 0;
}