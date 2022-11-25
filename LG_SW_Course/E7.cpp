#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int N;
int half;
int grids[500+10][500+10];
int visited[500+10][500+10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int> > group; //(넓이, 높이)
int maxHeight = -1, minHeight = 1000001;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> grids[i][j];
            maxHeight = max(maxHeight, grids[i][j]);
            minHeight = min(minHeight, grids[i][j]);
        }
    }
}

void Initialize()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
}

bool BFS(int startY, int startX, int idx, int D)
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
        if (cnt >= half)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
            {
                continue;
            }
            if (visited[nextY][nextX] > 0)
            {
                continue;
            }
            if (abs(grids[nextY][nextX] - grids[curY][curX]) <= D)
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = idx;
            }
        }
    }
    return false;
}

int Check(int D)
{
    Initialize();

    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0)
            {
                idx++;
                if (BFS(i, j, idx, D))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int BS(int low, int high) // Lower Bound
{
    if (low > high)
    {
        return low;
    }
    int mid = (low + high) / 2;
    if (Check(mid))
    {
        return BS(low, mid - 1);
    }
    else
    {
        return BS(mid + 1, high);
    }
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    half = (N * N + 1) / 2;
    ans = BS(0, maxHeight - minHeight);

    cout <<  ans << endl;// 출력하는 부분
    return 0;
}