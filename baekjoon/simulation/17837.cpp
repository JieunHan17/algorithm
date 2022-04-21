#include <cstdio>
#include <vector>
#include <utility>

#define MAX_N 13
#define MAX_K 11

using namespace std;

struct PIECE
{
    int row;
    int col;
    int dir;
};

int N;
int board[MAX_N][MAX_N];
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
vector<int> board_pieces[MAX_N][MAX_N]; // idx
PIECE pieces[11];

int getIdx(int curY, int curX, int piece)
{
    for (int i = 0; i < board_pieces[curY][curX].size(); i++)
    {
        if (board_pieces[curY][curX][i] == piece)
        {
            return i;
        }
    }
    return 0;
}

int changeDir(int dir)
{
    if (dir == 1)
    {
        return 2;
    }
    else if (dir == 2)
    {
        return 1;
    }
    else if (dir == 3)
    {
        return 4;
    }
    else
    {
        return 3;
    }
}

bool checkEscape(int piece_idx, int curY, int curX, int nextY, int nextX)
{
    if ((board_pieces[curY][curX].size() - piece_idx) + board_pieces[nextY][nextX].size() >= 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void goToWhite(int piece_idx, int curY, int curX, int nextY, int nextX)
{
    for (int i = piece_idx; i < board_pieces[curY][curX].size(); i++)
    {
        int idx = board_pieces[curY][curX][i];
        board_pieces[nextY][nextX].push_back(idx);
        pieces[idx].row = nextY;
        pieces[idx].col = nextX;
    }
    vector<int> temp;
    for (int i = 0; i < piece_idx; i++)
    {
        temp.push_back(board_pieces[curY][curX][i]);
    }
    board_pieces[curY][curX] = temp;
}

void goToRed(int piece_idx, int curY, int curX, int nextY, int nextX)
{
    for (int i = board_pieces[curY][curX].size() - 1; i >= piece_idx; i--)
    {
        int idx = board_pieces[curY][curX][i];
        board_pieces[nextY][nextX].push_back(idx);
        pieces[idx].row = nextY;
        pieces[idx].col = nextX;
    }
    vector<int> temp;
    for (int i = 0; i < piece_idx; i++)
    {
        temp.push_back(board_pieces[curY][curX][i]);
    }
    board_pieces[curY][curX] = temp;
}

int main()
{
    int K;
    scanf("%d %d", &N, &K);

    for (int i = 1; i<= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 1; i <= K; i++)
    {
        int row, col, dir;
        scanf("%d %d %d", &row, &col, &dir);
        board_pieces[row][col].push_back(i);
        pieces[i].row = row;
        pieces[i].col = col;
        pieces[i].dir = dir;
    }

    int turn = 1;
    while (turn <= 1000)
    {
        for (int k = 1; k <= K; k++)
        {
            int curY = pieces[k].row;
            int curX = pieces[k].col;
            int dir = pieces[k].dir;
            int piece_idx = getIdx(curY, curX, k);
            
            int nextY = curY + dy[dir];
            int nextX = curX + dx[dir];
            if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
            {
                dir = changeDir(dir);
                pieces[k].dir = dir;
                nextY = curY + dy[dir];
                nextX = curX + dx[dir];

                if (board[nextY][nextX] == 0)
                {
                    bool stop = checkEscape(piece_idx, curY, curX, nextY, nextX);
                    if (stop)
                    {
                        printf("%d", turn);
                        return 0;
                    }
                    goToWhite(piece_idx, curY, curX, nextY, nextX);
                }
                else if (board[nextY][nextX] == 1)
                {
                    bool stop = checkEscape(piece_idx, curY, curX, nextY, nextX);
                    if (stop)
                    {
                        printf("%d", turn);
                        return 0;
                    }
                    goToRed(piece_idx, curY, curX, nextY, nextX);
                }
                else if (board[nextY][nextX] == 2)
                {
                    continue;
                }
            }
            else
            {
                if (board[nextY][nextX] == 0)
                {
                    bool stop = checkEscape(piece_idx, curY, curX, nextY, nextX);
                    if (stop)
                    {
                        printf("%d", turn);
                        return 0;
                    }
                    goToWhite(piece_idx, curY, curX, nextY, nextX);
                }
                else if (board[nextY][nextX] == 1)
                {
                    bool stop = checkEscape(piece_idx, curY, curX, nextY, nextX);
                    if (stop)
                    {
                        printf("%d", turn);
                        return 0;
                    }
                    goToRed(piece_idx, curY, curX, nextY, nextX);
                }
                else if (board[nextY][nextX] == 2)
                {
                    dir = changeDir(dir);
                    pieces[k].dir = dir;
                    nextY = curY + dy[dir];
                    nextX = curX + dx[dir];

                    if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
                    {
                        continue;
                    }

                    if (board[nextY][nextX] == 0)
                    {
                        bool stop = checkEscape(piece_idx, curY, curX, nextY, nextX);
                        if (stop)
                        {
                            printf("%d", turn);
                            return 0;
                        }
                        goToWhite(piece_idx, curY, curX, nextY, nextX);
                    }
                    else if (board[nextY][nextX] == 1)
                    {
                        bool stop = checkEscape(piece_idx, curY, curX, nextY, nextX);
                        if (stop)
                        {
                            printf("%d", turn);
                            return 0;
                        }
                        goToRed(piece_idx, curY, curX, nextY, nextX);
                    }
                    else if (board[nextY][nextX] == 2)
                    {
                        continue;
                    }
                }
            }
        }
        turn++;
    }

    printf("-1");
    return 0;
}