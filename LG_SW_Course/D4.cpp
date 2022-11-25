#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN (100)

int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int sw, sh;//시작위치 가로 세로 좌표

int visited[MAXN+10][MAXN+10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
    cin >> sw >> sh;
}

int GetMaximum()
{
    queue<pair<int, int> > q;
    q.push(make_pair(sh, sw));
    visited[sh][sw] = 3;

    int maximum = visited[sh][sw];

    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY <= 0 || nextY > H || nextX <= 0 || nextX > W)
            {
                continue;
            }
            if (visited[nextY][nextX] > 0)
            {
                continue;
            }
            if (map[nextY][nextX] == '1')
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = visited[curY][curX] + 1;
                maximum = max(maximum, visited[nextY][nextX]);
            }
        }
    }
    return maximum;
}

int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    int ans1 = GetMaximum();
    int ans2 = 0;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (map[i][j] == '1' && visited[i][j] == 0)
            {
                ans2++;
            }
        }
    }

    cout << ans1 << "\n" << ans2;
    return 0;
}