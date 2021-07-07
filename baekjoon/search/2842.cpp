#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

/* 푸는 중 */
int N, highest = 1000001, lowest = 0, cnt_K = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int altitude[50][50] = {
    0,
};
string village[50];
bool visited[50][50] = {
    false,
};

bool validate(int y, int x)
{
    return 0 <= y && y < N && 0 <= x && x < N;
}

int bfs(int low, int high)
{
}

int main()
{
    int start_y, start_x;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        cin >> village[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &altitude[i][j]);
            if (village[i][j] == 'P')
            {
                start_y = i;
                start_x = j;
            }
            if (village[i][j] == 'K')
            {
                cnt_K++;
            }
        }
    }

    return 0;
}