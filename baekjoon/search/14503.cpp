#include <cstdio>

using namespace std;

int N, M, r, c, d;
int area[50][50];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
int left[4] = {3, 0, 1, 2};
int backX[4] = {0, -1, 0, 1};
int backY[4] = {1, 0, -1, 0};
int result = 1;

void search()
{
    for (int i = 0; i < 4; i++)
    {
        int nextR = r + dirY[d];
        int nextC = c + dirX[d];
        d = left[d];
        if (area[nextR][nextC] == 0)
        {
            r = nextR;
            c = nextC;
            area[r][c] = 2;
            result++;
            return search();
        }
    }
    r += backY[d];
    c += backX[d];
    if (area[r][c] == 1)
    {
        return;
    }
    search();
}

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &area[i][j]);
        }
    }
    area[r][c] = 2;
    search();
    printf("%d", result);
    return 0;
}