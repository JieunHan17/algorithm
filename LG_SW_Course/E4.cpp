#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];
int paper[MAX+10][MAX+10];
int visited[MAX+10][MAX+10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector<int> sol;

void InputData(){
    cin >> M >> N >> K;
    for (int i=0; i<K; i++){
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }
}
void OutputData(int ans){
    cout << ans << endl;
    sort(sol.begin(), sol.end());
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

void FillArea()
{
    for (int i = 0; i < K; i++)
    {
        for (int y = sy[i]; y < ey[i]; y++)
        {
            for (int x = sx[i]; x < ex[i]; x++)
            {
                paper[y][x] = -1;
            }
        }
    }
}

void Initialize()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int BFS(int startY, int startX, int idx)
{
    Initialize();

    int area = 0;

    queue<pair<int, int> > q;
    q.push(make_pair(startY, startX));
    visited[startY][startX] = 1;
    paper[startY][startX] = idx;

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        area++;
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
            {
                continue;
            }
            if (paper[nextY][nextX] != 0)
            {
                continue;
            }
            if (visited[nextY][nextX] > 0)
            {
                continue;
            }
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = visited[curY][curX] + 1;

            paper[nextY][nextX] = idx;
        }
    }

    return area;
}

int FloodFill()
{
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (paper[i][j] == 0)
            {
                cnt++;
                int area = BFS(i, j, cnt);
                sol.push_back(area);
            }
        }
    }
    return cnt;
}

int main(void){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    FillArea();
    ans = FloodFill();

    OutputData(ans);//출력하는 부분
    return 0;
}