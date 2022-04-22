#include <cstdio>

#define MAX_N 500

using namespace std;

int N;
int A[MAX_N][MAX_N];
int dy[4] = {0, 1, 0, -1}; //서남동북
int dx[4] = {-1, 0, 1, 0};
int outside = 0;

void checkOutside(int nextY, int nextX, int amount)
{
    if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
    {
        outside += amount;
    }
    else
    {
        A[nextY][nextX] += amount;
    }
}

void moveDust(int tornadoY, int tornadoX, int dir)
{
    int nextY, nextX;
    int amount = 0;
    /* 5% */
    nextY = tornadoY + 2 * dy[dir];
    nextX = tornadoX + 2 * dx[dir];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.05));
    amount += int(A[tornadoY][tornadoX] * 0.05);
    
    /* 10% */
    nextY = tornadoY + dy[dir] + dy[(dir + 1) % 4];
    nextX = tornadoX + dx[dir] + dx[(dir + 1) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.1));
    nextY = tornadoY + dy[dir] + dy[(dir + 3) % 4];
    nextX = tornadoX + dx[dir] + dx[(dir + 3) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.1));
    amount += int(A[tornadoY][tornadoX] * 0.1) * 2;

    /* 7% */
    nextY = tornadoY + dy[(dir + 1) % 4];
    nextX = tornadoX + dx[(dir + 1) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.07));
    nextY = tornadoY + dy[(dir + 3) % 4];
    nextX = tornadoX + dx[(dir + 3) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.07));
    amount += int(A[tornadoY][tornadoX] * 0.07) * 2;

    /* 2% */
    nextY = tornadoY + 2 * dy[(dir + 1) % 4];
    nextX = tornadoX + 2 * dx[(dir + 1) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.02));
    nextY = tornadoY + 2 * dy[(dir + 3) % 4];
    nextX = tornadoX + 2 * dx[(dir + 3) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.02));
    amount += int(A[tornadoY][tornadoX] * 0.02) * 2;

    /* 1% */
    nextY = tornadoY + dy[(dir + 2) % 4] + dy[(dir + 1) % 4];
    nextX = tornadoX + dx[(dir + 2) % 4] + dx[(dir + 1) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.01));
    nextY = tornadoY + dy[(dir + 2) % 4] + dy[(dir + 3) % 4];
    nextX = tornadoX + dx[(dir + 2) % 4] + dx[(dir + 3) % 4];
    checkOutside(nextY, nextX, int(A[tornadoY][tornadoX] * 0.01));
    amount += int(A[tornadoY][tornadoX] * 0.01) * 2;

    /* alpha */
    int rest = A[tornadoY][tornadoX] - amount;
    nextY = tornadoY + dy[dir];
    nextX = tornadoX + dx[dir];
    checkOutside(nextY, nextX, rest);

    A[tornadoY][tornadoX] = 0;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int tornadoY = N / 2 + 1;
    int tornadoX = N / 2 + 1;
    int dir = 0;
    int cntArrows = (N - 1) * 2 + 1;
    for (int i = 0; i < cntArrows; i++)
    {
        int lenOfArrow = 2 + i / 2;
        for (int j = 1; j < lenOfArrow; j++)
        {
            tornadoY = tornadoY + dy[dir];
            tornadoX = tornadoX + dx[dir];
            moveDust(tornadoY, tornadoX, dir);
        }
        dir = (dir + 1) % 4;
    }
    printf("%d", outside);
    return 0;
}