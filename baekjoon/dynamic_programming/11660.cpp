#include <cstdio>
#define MAX 1025

using namespace std;

int board[MAX][MAX] = {
    0,
};
int dp[MAX][MAX] = {
    0,
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + board[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        int startRow, startCol, endRow, endCol;
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
        printf("%d\n", dp[endRow][endCol] - dp[startRow - 1][endCol] - dp[endRow][startCol - 1] + dp[startRow - 1][startCol - 1]);
    }

    return 0;
}