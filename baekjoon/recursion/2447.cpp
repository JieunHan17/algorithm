#include <iostream>

#define MAX_N 6561

using namespace std;

char ans[MAX_N][MAX_N];

void pattern(int N, int startY, int startX)
{
    for (int i = startY; i < startY + N; i++)
    {
        for (int j = startX; j < startX + N; j++)
        {
            if (i == startY + 1 && j == startX + 1)
            {
                ans[i][j] = ' ';
                continue;
            }
            ans[i][j] = '*';
        }
    }
}

void blank(int N, int startY, int startX)
{
    for (int i = startY; i < startY + N; i++)
    {
        for (int j = startX; j < startX + N; j++)
        {
            ans[i][j] = ' ';
        }
    }
}

void recur(int N, int startY, int startX)
{
    if (N == 3)
    {
        pattern(N, startY, startX);
        return;
    }

    recur(N / 3, startY, startX);
    recur(N / 3, startY, startX + N / 3);
    recur(N / 3, startY, startX + 2 * N / 3);

    recur(N / 3, startY + N / 3, startX);
    blank(N / 3, startY + N / 3, startX + N / 3);
    recur(N / 3, startY + N / 3, startX + 2 * N / 3);

    recur(N / 3, startY + 2 * N / 3, startX);
    recur(N / 3, startY + 2 * N / 3, startX + N / 3);
    recur(N / 3, startY + 2 * N / 3, startX + 2 * N / 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    recur(N, 0, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}