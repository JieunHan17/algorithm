#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int board[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int> > empty_board;
bool finish = false;

bool case1(int y, int x)
{
    int box_y = 0;
    int box_x = 0;

    if (0 <= y && y < 3 && 0 <= x && x < 3)
    {
        box_y = 2;
        box_x = 2;
    }
    else if (0 <= y && y < 3 && 3 <= x && x < 6)
    {
        box_y = 2;
        box_x = 5;
    }
    else if (0 <= y && y < 3 && 6 <= x && x < 9)
    {
        box_y = 2;
        box_x = 8;
    }
    else if (3 <= y && y < 6 && 0 <= x && x < 3)
    {
        box_y = 5;
        box_x = 2;
    }
    else if (3 <= y && y < 6 && 3 <= x && x < 6)
    {
        box_y = 5;
        box_x = 5;
    }
    else if (3 <= y && y < 6 && 6 <= x && x < 9)
    {
        box_y = 5;
        box_x = 8;
    }
    else if (6 <= y && y < 9 && 0 <= x && x < 3)
    {
        box_y = 8;
        box_x = 2;
    }
    else if (6 <= y && y < 9 && 3 <= x && x < 6)
    {
        box_y = 8;
        box_x = 5;
    }
    else if (6 <= y && y < 9 && 6 <= x && x < 9)
    {
        box_y = 8;
        box_x = 8;
    }

    for (int i = box_y - 2; i <= box_y; i++)
    {
        for (int j = box_x - 2; j <= box_x; j++)
        {
            if (board[i][j] == board[y][x] && i != y && j != x)
            {
                return false;
            }
        }
    }

    return true;
}

bool case2(int y, int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][x] == board[y][x] && i != y)
        {
            return false;
        }
    }
    return true;
}

bool case3(int y, int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[y][i] == board[y][x] && i != x)
        {
            return false;
        }
    }
    return true;
}

void backtracking(int index)
{
    if (index == empty_board.size())
    {
        finish = true;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        return;
    }

    int y = empty_board[index].first;
    int x = empty_board[index].second;
    for (int i = 1; i <= 9; i++)
    {
        board[y][x] = i;
        if (case1(y, x) && case2(y, x) && case3(y, x))
        {
            backtracking(index + 1);
        }
        if (finish)
        {
            return;
        }
    }
    board[y][x] = 0;
    return;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0)
            {
                empty_board.push_back(make_pair(i, j));
            }
        }
    }

    backtracking(0);
}