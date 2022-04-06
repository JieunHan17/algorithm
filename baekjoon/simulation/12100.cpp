#include <cstdio>
#include <algorithm>

#define MAX 21

using namespace std;

int N;
int board[MAX][MAX];
int board_copy[MAX][MAX];

void rotateBoard()
{
    int temp[MAX][MAX];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = board_copy[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board_copy[i][j] = temp[N - 1 - j][i];
        }
    }
}

void func(int dir)
{
    while(dir--)
    {
        rotateBoard();
    }
 
    for (int i = 0; i < N; i++)
    {
        int temp[MAX] = {}; // 전역변수 배열이 아니므로 초기화 필수
        int idx = 0;
        for (int j = 0; j < N; j++)
        {
            if (board_copy[i][j] != 0)
            {
                if (temp[idx] == 0)
                {
                    temp[idx] = board_copy[i][j];
                }
                else if (temp[idx] == board_copy[i][j])
                {
                    temp[idx] += board_copy[i][j];
                    idx++; // 이렇게 인덱스를 증가시키므로 해당 블록이 중복으로 충돌될 가능성 배제
                }
                else
                {
                    idx++;
                    temp[idx] = board_copy[i][j];
                }
            }
        }
        for (int j = 0; j < N; j++)
        {
            board_copy[i][j] = temp[j];
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int ans = 0;
    for (int temp = 0; temp < (1<<(2*5)); temp++) // 1<<(2*5)는 4의 5승
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board_copy[i][j] = board[i][j];
            }
        }
        int num = temp;
        for (int i = 0; i < 5; i++)
        {
            int dir = num % 4;
            num /= 4;
            func(dir);
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ans = max(ans, board_copy[i][j]);
            }
        }
    }

    printf("%d", ans);
    return 0;
}