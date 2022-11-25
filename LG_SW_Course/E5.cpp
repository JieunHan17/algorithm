#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define MAXH (12)
#define MAXW (6)

char map[MAXH+2][MAXW+2];
int visited[MAXH+2][MAXW+2];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}

void Initialize()
{
    for (int i = 1; i <= MAXH; i++)
    {
        for (int j = 1; j <= MAXW; j++)
        {
            visited[i][j] = 0;
        }
    }
}

bool BFS(int startY, int startX, int idx)
{
    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = idx;

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
            if (nextY <= 0 || nextY > MAXH || nextX <= 0 || nextX > MAXW)
            {
                continue;
            }
            if (visited[nextY][nextX] > 0)
            {
                continue;
            }
            if (map[nextY][nextX] == map[startY][startX])
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = idx;
            }
        }
    }

    if (cnt >= 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bomb()
{
    Initialize();

    int idx = 0;
    vector<int> v;
    for (int i = 1; i <= MAXH; i++)
    {
        for (int j = 1; j <= MAXW; j++)
        {
            if (map[i][j] != '.' && visited[i][j] == 0)
            {
                idx++;
                bool isThereGroup = BFS(i, j, idx);

                if (isThereGroup)
                {
                    v.push_back(idx);
                }
            }
        }
    }

    if (v.size() == 0)
    {
        return false;
    }

    for (int k = 0; k < v.size(); k++)
    {
        int area = v[k];
        for (int i = 1; i <= MAXH; i++)
        {
            for (int j = 1; j <= MAXW; j++)
            {
                if (visited[i][j] == area)
                {
                    map[i][j] = '.';
                }
            }
        }
    }
    return true;
}

void Drop()
{
    for (int i = 1; i <= 6; i++)
    {
        int start = 12;
        while (map[start][i] != '.')
        {
            start--;
        }
        int end = start;
        while (end > 0)
        {
            if (map[end][i] != '.' && start != end)
            {
                map[start][i] = map[end][i];
                map[end][i] = '.';
                start--;
            }
            end--;
        }
    }
}

int main(){
    int T, t;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        
        int ans = 0;
        while (1)
        {
            bool isThereBomb = Bomb();
            if (isThereBomb)
            {
                ans++;
                Drop();
            }
            else
            {
                break;
            }
        }

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}