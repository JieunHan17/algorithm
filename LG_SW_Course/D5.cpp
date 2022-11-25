#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN (15)

int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
int visited[MAXN+5][MAXN+5][MAXN+5][MAXN+5];
int RStartY, RStartX;
int BStartY, BStartX;
int GoalY, GoalX;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData(){
	cin >> R >> C;
	for (int i=0; i<R; i++){
		cin >> map[i];
	}
}

void GetCoordinates()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'R')
            {
                RStartY = i;
                RStartX = j;
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B')
            {
                BStartY = i;
                BStartX = j;
                map[i][j] = '.';
            }
            else if (map[i][j] == 'H')
            {
                GoalY = i;
                GoalX = j;
            }
        }
    }
}

void Initialize()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            for (int k = 0; k < R; k++)
            {
                for (int l = 0; l < C; l++)
                {
                    visited[i][j][k][l] = -1;
                }
            }
        }
    }
}

int BFS()
{
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(RStartY, RStartX), make_pair(BStartY, BStartX)));
    visited[RStartY][RStartX][BStartY][BStartX] = 0;
    
    int cnt;
    while (!q.empty())
    {
        int RCurY = q.front().first.first;
        int RCurX = q.front().first.second;
        int BCurY = q.front().second.first;
        int BCurX = q.front().second.second;
        q.pop();

        cnt = visited[RCurY][RCurX][BCurY][BCurX];
        if (cnt >= 10)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int RNextY = RCurY + dy[i];
            int RNextX = RCurX + dx[i];
            int BNextY = BCurY + dy[i];
            int BNextX = BCurX + dx[i];
            if (RNextY == BNextY && RNextX == BNextX)
            {
                continue;
            }
            else if (BNextY == GoalY && BNextX == GoalX)
            {
                continue;
            }
            else if (RNextY == GoalY && RNextX == GoalX)
            {
                return cnt + 1;
            }

            if (map[RNextY][RNextX] == '.' && map[BNextY][BNextX] == '.')
            {
                if (visited[RNextY][RNextX][BNextY][BNextX] >= 0)
                {
                    continue;
                }
                q.push(make_pair(make_pair(RNextY, RNextX), make_pair(BNextY, BNextX)));
                visited[RNextY][RNextX][BNextY][BNextX] = visited[RCurY][RCurX][BCurY][BCurX] + 1;
            }
            else if (map[RNextY][RNextX] == '.')
            {
                if (visited[RNextY][RNextX][BCurY][BCurX] >= 0)
                {
                    continue;
                }
                q.push(make_pair(make_pair(RNextY, RNextX), make_pair(BCurY, BCurX)));
                visited[RNextY][RNextX][BCurY][BCurX] = visited[RCurY][RCurX][BCurY][BCurX] + 1;
            }
            else if (map[BNextY][BNextX] == '.')
            {
                if (visited[RCurY][RCurX][BNextY][BNextX] >= 0)
                {
                    continue;
                }
                q.push(make_pair(make_pair(RCurY, RCurX), make_pair(BNextY, BNextX)));
                visited[RCurY][RCurX][BNextY][BNextX] = visited[RCurY][RCurX][BCurY][BCurX] + 1;
            }
        }
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, ans=-10;
	cin >> T;

	for (int i=0; i<T; i++){
		InputData();//입력

		//여기서부터 작성
        GetCoordinates();
        Initialize();
        ans = BFS();

		cout << ans << "\n";//출력
	}
	return 0;
}