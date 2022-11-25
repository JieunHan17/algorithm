#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN (1000)

int H, W;
char map[MAXN+10][MAXN+10];
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void InputData(){
    cin >> H >> W;
    for (int i=0; i<H; i++){
        cin >> map[i];
    }
}

int BFS()
{
    int cnt;

    queue<pair<pair<int, int>, int> > q;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map[i][j] == '.')
            {
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }

    while (!q.empty())
    {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curCnt = q.front().second;
        cnt = curCnt;
        q.pop();
        
        for (int i = 0; i < 8; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= H || nextX < 0 || nextX >= W)
            {
                continue;
            }
            if (map[nextY][nextX] >= '1' && map[nextY][nextX] <= '9')
            {
                map[nextY][nextX]--;
            }
            if (map[nextY][nextX] == '0')
            {
                map[nextY][nextX] = '.';
                q.push(make_pair(make_pair(nextY, nextX), curCnt + 1));
            }
        }
    }
    return cnt;
}

int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = BFS();
    cout << ans << endl;//출력하는 부분
    return 0;
}