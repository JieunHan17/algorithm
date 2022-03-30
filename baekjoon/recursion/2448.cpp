#include <iostream>

#define MAX_N 3073

using namespace std;

char ans[MAX_N][MAX_N * 2];

void recur(int N, int startY, int startX)
{
    if (N == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            ans[startY][startX + i] = '*';
        }
        ans[startY - 1][startX + 1] = '*';
        ans[startY - 1][startX + 3] = '*';
        ans[startY - 2][startX + 2] = '*';
        return;
    }
    recur(N / 2, startY, startX);
    recur(N / 2, startY - N / 2, startX + N / 2);
    recur(N / 2, startY, startX + N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            ans[i][j] = ' ';
        }
    }

    recur(N, N - 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}