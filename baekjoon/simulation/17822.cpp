#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

#define MAX 51

using namespace std;

int N, M;
deque<int> board[MAX];

void rotateBoard(int idx, int d, int k)
{
    while (k--)
    {
        if (d == 0)
        {
            board[idx].push_front(board[idx].back());
            board[idx].pop_back();
        }
        else if (d == 1)
        {
            board[idx].push_back(board[idx].front());
            board[idx].pop_front();
        }
    }
}

bool removeSameNumbers(int M)
{
    int dy[4] = {-1, 0, 1, 0}; // 북동남서
    int dx[4] = {0, 1, 0, M - 1};

    deque<int> board_copy[MAX];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            board_copy[i].push_back(board[i][j]);
        }
    }

    bool isThereSameNum = false;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
            {
                int nextBoardIdx = i + dy[k];
                if (nextBoardIdx < 1 || nextBoardIdx > N)
                {
                    continue;
                }
                int nextNum = ((j + dx[k]) % M);
                if (board[nextBoardIdx][nextNum] == board[i][j])
                {
                    isThereSameNum = true;
                    board_copy[i][j] = 0;
                    board_copy[nextBoardIdx][nextNum] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            board[i][j] = board_copy[i][j];
        }
    }

    return isThereSameNum;
}

int getTotal()
{
    int total = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            total += board[i][j];
        }
    }

    return total;
}

int getCnt()
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] != 0)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int T;
    scanf("%d %d %d", &N, &M, &T);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            scanf("%d", &num);
            board[i].push_back(num);
        }
    }

    while (T--)
    {
        int x, d, k;
        scanf("%d %d %d", &x, &d, &k);
        for (int i = 1; i <= N; i++)
        {
            if (i % x == 0)
            {
                rotateBoard(i, d, k);
            }
        }

        bool isThereSameNum = removeSameNumbers(M);
        if (!isThereSameNum)
        {
            double avg = double(getTotal()) / double(getCnt());
            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (board[i][j] == 0)
                    {
                        continue;
                    }
                    if (board[i][j] > avg)
                    {
                        board[i][j]--;
                    }
                    else if (board[i][j] < avg)
                    {
                        board[i][j]++;
                    }
                }
            }
        }
    }

    printf("%d", getTotal());
    return 0;
}