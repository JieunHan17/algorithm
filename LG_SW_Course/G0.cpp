#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN (100)

int N;
int K;
int R[MAXN+10];
int C[MAXN+10];
int L;
int X[MAXN+10];
char CMD[MAXN+10];

bool fruits[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10]; //방향 저장
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int changeDirIdx = 0;
int tailY, tailX;

void InputData(){
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> R[i] >> C[i];
        fruits[R[i]][C[i]] = true;
    }
    cin >> L;
    for (int i=0; i<L; i++){
        cin >> X[i] >> CMD[i];
    }
}

void Initialize()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            visited[i][j] = -1;
        }
    }
}

int BFS()
{
    Initialize();
    int cnt = 0;

    queue<pair<pair<int, int>, int> > q; //(y좌표, x좌표), 방향
    q.push(make_pair(make_pair(1, 1), 0));
    visited[1][1] = 0;
    tailY = 1;
    tailX = 1;

    while (!q.empty())
    {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int curDir = q.front().second;
        q.pop();
        cnt++;
        int nextY = curY + dy[curDir];
        int nextX = curX + dx[curDir];
        int nextDir = curDir;
        if (nextY <= 0 || nextY > N || nextX <= 0 || nextX > N)
        {
            return cnt;
        }
        if (visited[nextY][nextX] != -1)
        {
            return cnt;
        }
        
        if (cnt == X[changeDirIdx])
        {
            if (CMD[changeDirIdx] == 'L')
            {
                nextDir = (nextDir + 1) % 4;
            }
            else
            {
                nextDir = (nextDir + 3) % 4;
            }
            changeDirIdx++;
        }
        q.push(make_pair(make_pair(nextY, nextX), nextDir));
        visited[nextY][nextX] = nextDir;
        if (fruits[nextY][nextX])
        {
            fruits[nextY][nextX] = false;
        }
        else
        {
            int tailDir = visited[tailY][tailX];
            visited[tailY][tailX] = -1;
            tailY += dy[tailDir];
            tailX += dx[tailDir];
        }
    }
    return -1;
}

int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = BFS();

    cout << ans << endl;//출력하는 부분
    return 0;
}