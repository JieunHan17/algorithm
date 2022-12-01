#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXH (5)
#define MAXW (9)
#define INF (1e4)

char map[MAXH+2][MAXW+2];
int solremain, solmove;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void InputData(){
    for (int h = 1; h <= MAXH; h++){
        cin >> &map[h][1];
    }
}

queue<pair<pair<int, int>, int> > Check()
{
    queue<pair<pair<int, int>, int> > q;
    for (int h = 1; h <= MAXH; h++)
    {
        for (int w = 1; w <= MAXW; w++)
        {
            if (map[h][w] == 'o')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nextY = h + dy[k];
                    int nextX = w + dx[k];
                    if (map[nextY][nextX] == 'o' && map[nextY + dy[k]][nextX + dx[k]] == '.')
                    {
                        q.push(make_pair(make_pair(h, w), k));
                    }
                }
            }
        }
    }
    return q;
}

void DFS(int cntMove)
{
    queue<pair<pair<int, int>, int> > pins;
    pins = Check();
    if (pins.empty())
    {
        int cntPins = 0;
        for (int h = 1; h <= MAXH; h++)
        {
            for (int w = 1; w <= MAXW; w++)
            {
                if (map[h][w] == 'o')
                {
                    cntPins++;
                }
            }
        }

        if (cntPins < solremain)
        {
            solremain = cntPins;
            solmove = cntMove;
        }
        return;
    }

    while (!pins.empty())
    {
        int curY = pins.front().first.first;
        int curX = pins.front().first.second;
        int dir = pins.front().second;
        pins.pop();

        map[curY][curX] = '.';
        map[curY + dy[dir]][curX + dx[dir]] = '.';
        map[curY + 2 * dy[dir]][curX + 2 * dx[dir]] = 'o';
        DFS(cntMove + 1);
        map[curY][curX] = 'o';
        map[curY + dy[dir]][curX + dx[dir]] = 'o';
        map[curY + 2 * dy[dir]][curX + 2 * dx[dir]] = '.';
    }

}

int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        solremain = INF;
        solmove = INF;
        DFS(0);

        cout << solremain << " " << solmove << endl;//출력하는 부분
    }
    return 0;
}