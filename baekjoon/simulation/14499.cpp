#include <cstdio>
#include <utility>

#define MAX 20

using namespace std;

int map[MAX][MAX] = {
    0,
};
pair<int, int> direction[5]; //(dir_y, dir_x)
int dice[7] = {
    0,
};

int main()
{
    int N, M, x, y, K;
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    direction[1] = make_pair(0, 1);
    direction[2] = make_pair(0, -1);
    direction[3] = make_pair(-1, 0);
    direction[4] = make_pair(1, 0);

    int cur_y = x;
    int cur_x = y;
    for (int i = 0; i < K; i++)
    {
        int query;
        scanf("%d", &query);

        int next_y = cur_y + direction[query].first;
        int next_x = cur_x + direction[query].second;
        if (next_y < 0 || N <= next_y || next_x < 0 || M <= next_x)
        {
            continue;
        }

        int new_dice[7] = {
            0,
        };
        if (query == 1)
        {
            new_dice[1] = dice[4];
            new_dice[2] = dice[2];
            new_dice[3] = dice[1];
            new_dice[4] = dice[6];
            new_dice[5] = dice[5];
            new_dice[6] = dice[3];
        }
        else if (query == 2)
        {
            new_dice[1] = dice[3];
            new_dice[2] = dice[2];
            new_dice[3] = dice[6];
            new_dice[4] = dice[1];
            new_dice[5] = dice[5];
            new_dice[6] = dice[4];
        }
        else if (query == 3)
        {
            new_dice[1] = dice[5];
            new_dice[2] = dice[1];
            new_dice[3] = dice[3];
            new_dice[4] = dice[4];
            new_dice[5] = dice[6];
            new_dice[6] = dice[2];
        }
        else
        {
            new_dice[1] = dice[2];
            new_dice[2] = dice[6];
            new_dice[3] = dice[3];
            new_dice[4] = dice[4];
            new_dice[5] = dice[1];
            new_dice[6] = dice[5];
        }

        for (int j = 0; j < 7; j++)
        {
            dice[j] = new_dice[j];
        }

        if (map[next_y][next_x] != 0)
        {
            dice[6] = map[next_y][next_x];
            map[next_y][next_x] = 0;
        }
        else
        {
            map[next_y][next_x] = dice[6];
        }
        printf("%d\n", dice[1]);
        cur_y = next_y;
        cur_x = next_x;
    }

    return 0;
}