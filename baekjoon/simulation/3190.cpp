#include <iostream>
#include <queue>
#include <utility>
#include <unordered_map>

#define MAX 101
using namespace std;

int N, K, L;
int board[MAX][MAX];
int dy[4] = {0, 1, 0, -1}; // 동 남 서 북
int dx[4] = {1, 0, -1, 0};
int ans = 0;
queue<pair<int, int> > tail;
unordered_map<int, char> trans;

int changeDir(int curDir, char op)
{
    if (op == 'L')
    {
        if (curDir == 0)
            return 3;
        else
            return curDir - 1;
    }
    else
    {
        if (curDir == 3)
            return 0;
        else
            return curDir + 1;
    }
}

void move(int curY, int curX, int curDir)
{
    ans++;

    int nextY = curY + dy[curDir];
    int nextX = curX + dx[curDir];
    int tailY = tail.front().first;
    int tailX = tail.front().second;

    if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
        return;
    if (board[nextY][nextX] == -1)
        return;

    if (board[nextY][nextX] != 1)
    {
        board[tailY][tailX] = 0;
        tail.pop();
    }
    board[nextY][nextX] = -1;
    tail.push(make_pair(nextY, nextX));

    if (trans.find(ans) != trans.end())
    {
        curDir = changeDir(curDir, trans[ans]);
    }
    move(nextY, nextX, curDir);    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    while (K--)
    {
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1] = 1;
    }

    cin >> L;
    while (L--)
    {
        int X;
        char C;
        cin >> X >> C;
        trans[X] = C;
    }

    board[0][0] = -1;
    tail.push(make_pair(0, 0));
    move(0, 0, 0);

    cout << ans;
    return 0;
}