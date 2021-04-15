#include <stdio.h>

char board[8][8];

int palindrome(int n)
{
    int cnt = 0;
    bool flag = true;

    /* 가로 탐색 */
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < (9 - n); j++)
        {
            for (int k = 0; k < n / 2; k++)
            {
                if (board[i][j + k] != board[i][j - k + n - 1])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                cnt++;
            }
            flag = true;
        }
    }

    /* 세로 탐색 */
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < (9 - n); j++)
        {
            for (int k = 0; k < n / 2; k++)
            {
                if (board[j + k][i] != board[j - k + n - 1][i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                cnt++;
            }
            flag = true;
        }
    }

    return cnt;
}

int main()
{
    int n;
    int i, j;
    int test_case = 1;

    scanf("%d", &n);

    for (i = 0; i < 8; i++)
    {
        getchar();
        for (j = 0; j < 8; j++)
        {
            scanf("%c", &board[i][j]);
        }
    }

    printf("#%d %d\n", test_case, palindrome(n));

    return 0;
}