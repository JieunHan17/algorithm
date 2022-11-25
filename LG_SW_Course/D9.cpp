#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN (100)
#define MAX 987654321

int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
        }
    }
}

void Initialize()
{
    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j<= N + 1; j++)
        {
            visited[i][j] = MAX;
        }
    }
}

int BFS()
{
    queue<pair<int, int> > q;
    for (int i = 0; i <= N + 1; i++)
    {
        q.push(make_pair(i, 0));
        visited[i][0] = 0;
        q.push(make_pair(i, N + 1));
        visited[i][N + 1] = 0;
    }
    for (int j = 1; j <= N; j++)
    {
        q.push(make_pair(0, j));
        visited[0][j] = 0;
        q.push(make_pair(N + 1, j));
        visited[N + 1][j] = 0;
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
            if (nextY < 0 || nextY > N + 1 || nextX < 0 || nextX > N + 1)
            {
                continue;
            }
            
            int power;
            if (map[nextY][nextX] == map[curY][curX])
            {
                power = visited[curY][curX];
            }
            else if (map[nextY][nextX] < map[curY][curX])
            {
                power = visited[curY][curX] + (map[curY][curX] - map[nextY][nextX]);
            }
            else
            {
                power = visited[curY][curX] + (map[nextY][nextX] - map[curY][curX]) * (map[nextY][nextX] - map[curY][curX]);
            }

            if (power < visited[nextY][nextX])
            {
                q.push(make_pair(nextY, nextX));
                visited[nextY][nextX] = power;
            }
        }
    }
    return visited[eh][ew];
}

int main(){
    int ans = -1;
    InputData();//입력 받는 부분

    //여기서부터 작성
    Initialize();
    ans = BFS();

    cout << ans << endl;//출력하는 부분
    return 0;
}