#include <cstdio>

#define MAX_N 128

using namespace std;

int paper[MAX_N][MAX_N];
int white = 0, blue = 0;

bool isDifferent(int N, int startY, int startX)
{
    int init = paper[startY][startX];
    bool ans = false;
    for (int i = startY; i < startY + N; i++)
    {
        for (int j = startX; j < startX + N; j++)
        {
            if (paper[i][j] != init)
            {
                ans = true;
                return ans;
            }
        }
    }
    return ans;
}

void recur(int N, int startY, int startX)
{
    bool flag = isDifferent(N, startY, startX);

    if (!flag)
    {
        if (paper[startY][startX])
        {
            blue++;
        }
        else
        {
            white++;
        }
        return;
    }
    recur(N / 2, startY, startX);
    recur(N / 2, startY, startX + N / 2);
    recur(N / 2, startY + N / 2, startX);
    recur(N / 2, startY + N / 2, startX + N / 2);
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &paper[i][j]);
        }
    }

    recur(N, 0, 0);

    printf("%d\n", white);
    printf("%d\n", blue);
    return 0;
}