#include <cstdio>

using namespace std;

bool board[2][4][6];
int score = 0;

void moveBlockInBlue(int t, int row)
{
    int empty = -1;
    if (t == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!board[0][row][i])
            {
                empty = i;
                if (i == 5)
                {
                    board[0][row][empty] = true;
                }
                continue;
            }
            else
            {
                if (empty != -1)
                {
                    board[0][row][empty] = true;
                }
                break;
            }
        }
    }
    else if (t == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            if (!board[0][row][i] && !board[0][row][i + 1])
            {
                empty = i;
                if (i == 4)
                {
                    board[0][row][empty] = true;
                    board[0][row][empty + 1] = true;
                }
                continue;
            }
            else
            {
                if (empty != -1)
                {
                    board[0][row][empty] = true;
                    board[0][row][empty + 1] = true;
                }
                break;
            }
        }
    }
    else if (t == 3)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!board[0][row][i] && !board[0][row + 1][i])
            {
                empty = i;
                if (i == 5)
                {
                    board[0][row][empty] = true;
                    board[0][row + 1][empty] = true;
                }
                continue;
            }
            else
            {
                if (empty != -1)
                {
                    board[0][row][empty] = true;
                    board[0][row + 1][empty] = true;
                }
                break;
            }
        }
    }
}

void moveBlockInGreen(int t, int row)
{
    int empty = -1;
    if (t == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!board[1][row][i])
            {
                empty = i;
                if (i == 5)
                {
                    board[1][row][empty] = true;
                }
                continue;
            }
            else
            {
                if (empty != -1)
                {
                    board[1][row][empty] = true;
                }
                break;
            }
        }
    }
    else if (t == 2)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!board[1][row][i] && !board[1][row + 1][i])
            {
                empty = i;
                if (i == 5)
                {
                    board[1][row][empty] = true;
                    board[1][row + 1][empty] = true;
                }
                continue;
            }
            else
            {
                if (empty != -1)
                {
                    board[1][row][empty] = true;
                    board[1][row + 1][empty] = true;
                }
                break;
            }
        }
    }
    else if (t == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            if (!board[1][row][i] && !board[1][row][i + 1])
            {
                empty = i;
                if (i == 4)
                {
                    board[1][row][empty] = true;
                    board[1][row][empty + 1] = true;
                }
                continue;
            }
            else
            {
                if (empty != -1)
                {
                    board[1][row][empty] = true;
                    board[1][row][empty + 1] = true;
                }
                break;
            }
        }
    }
}

void removeBlocks()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 5; j >= 0; j--)
        {
            if (board[i][0][j] && board[i][1][j] && board[i][2][j] && board[i][3][j])
            {
                for (int k = 0; k < 4; k++)
                {
                    board[i][k][j] = false;
                }
                score++;
            }
        }
    }
}

void relocateBlocks()
{
    for (int i = 0; i < 2; i++)
    {
        int empty = 6;
        for (int j = 5; j >= 0; j--)
        {
            if (!board[i][0][j] && !board[i][1][j] && !board[i][2][j] && !board[i][3][j])
            {
                if (empty == 6)
                {
                    empty = j;
                }
                continue;
            }
            if (empty != 6)
            {
                for (int k = 0; k < 4; k++)
                {
                    board[i][k][empty] = board[i][k][j];
                    board[i][k][j] = false;
                }
                empty--;
            }
        }
    }
}

void manageSpecialCase(int cnt, int idx)
{
    for (int j = 5; j > cnt - 1; j--)
    {
        for (int i = 0; i < 4; i++)
        {
            board[idx][i][j] = board[idx][i][j - cnt];
            board[idx][i][j - cnt] = false;
        }
    }
}

void checkSpecialCase()
{
    for (int i = 0; i < 2; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 2; j++)
        {
            bool isThereBlock = false;
            for (int k = 0; k < 4; k++)
            {
                if (board[i][k][j])
                {
                    isThereBlock = true;
                    break;
                }
            }
            if (isThereBlock)
            {
                cnt++;
            }
        }
        if (cnt > 0)
        {
            manageSpecialCase(cnt, i);
        }
    }
}

int getCntOfBlocks()
{
    int cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if (board[i][j][k])
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        moveBlockInBlue(t, x);
        moveBlockInGreen(t, y);
        removeBlocks();
        relocateBlocks();
        checkSpecialCase();
    }
    printf("%d\n", score);
    printf("%d", getCntOfBlocks());
    return 0;
}