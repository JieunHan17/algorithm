#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAX_SIZE (30)

int L, R, C;
int startZ, startY, startX;
char map[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];
int dz[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};
int visited[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];

bool InputData(){
    cin >> L >> R >> C;
    if ((L == 0) && (R == 0) && (C == 0)) return false;
    for (int l=0; l<L;l++){
        for (int r=0; r<R; r++){
            cin >> map[l][r];
            for (int c=0; c<C; c++){
                if (map[l][r][c] == 'S')
                {
                    startZ = l;
                    startY = r;
                    startX = c;
                }
            }
        }
    }
    return true;
}

void Initialize()
{
    for (int l = 0; l < L; l++)
    {
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                visited[l][r][c] = -1;
            }
        }
    }
}

int BFS()
{
    Initialize();

    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(startY, startX), startZ));
    visited[startZ][startY][startX] = 0;

    while (!q.empty())
    {
        int curZ = q.front().second;
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nextZ = curZ + dz[i];
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextZ < 0 || nextZ >= L || nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
            {
                continue;
            }
            if (visited[nextZ][nextY][nextX] >= 0)
            {
                continue;
            }
            if (map[nextZ][nextY][nextX] == 'E')
            {
                return visited[curZ][curY][curX] + 1;
            }
            if (map[nextZ][nextY][nextX] == '.')
            {
                q.push(make_pair(make_pair(nextY, nextX), nextZ));
                visited[nextZ][nextY][nextX] = visited[curZ][curY][curX] + 1;
            }
        }
    }
    return -1;
}

int main(){
    int ans = -1;
    while(InputData()){

        //여기서부터 작성
        ans = BFS();

        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}