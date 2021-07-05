#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int R, C;
string forest[50];
int start_x = 0, start_y = 0;
int goal_x = 0, goal_y = 0;
vector<pair<int, int> > water;
bool visited_hedgehog[50][50] = {
    false,
};
bool visited_water[50][50] = {
    false,
};
int checked_hedgehog[50][50] = {
    0,
};
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

bool validate(int y, int x)
{
    return 0 <= y && y < R && 0 <= x && x < C;
}

int bfs()
{
    queue<pair<int, int> > q_hedgehog;
    q_hedgehog.push(make_pair(start_y, start_x));
    visited_hedgehog[start_y][start_x] = true;

    queue<pair<int, int> > q_water;
    int water_size = water.size();
    for (int i = 0; i < water_size; i++)
    {
        q_water.push(make_pair(water[i].first, water[i].second));
        visited_water[water[i].first][water[i].second] = true;
    }

    while (!q_hedgehog.empty())
    {
        int water_queue_size = q_water.size();
        for (int idx = 0; idx < water_queue_size; idx++)
        {
            int cur_water_y = q_water.front().first;
            int cur_water_x = q_water.front().second;
            q_water.pop();

            // printf("water: %d %d\n", cur_water_y, cur_water_x);

            for (int i = 0; i < 4; i++)
            {
                int next_water_y = cur_water_y + dir_y[i];
                int next_water_x = cur_water_x + dir_x[i];
                if (!validate(next_water_y, next_water_x))
                {
                    continue;
                }

                if (!visited_water[next_water_y][next_water_x] && forest[next_water_y][next_water_x] != 'X' && forest[next_water_y][next_water_x] != 'S' && forest[next_water_y][next_water_x] != 'D')
                {
                    q_water.push(make_pair(next_water_y, next_water_x));
                    visited_water[next_water_y][next_water_x] = true;
                    forest[next_water_y][next_water_x] = '*';
                }
            }
        }

        int hedgehog_queue_size = q_hedgehog.size();
        for (int idx = 0; idx < hedgehog_queue_size; idx++)
        {
            int cur_hedgehog_y = q_hedgehog.front().first;
            int cur_hedgehog_x = q_hedgehog.front().second;
            q_hedgehog.pop();

            // printf("hedgehog: %d %d\n", cur_hedgehog_y, cur_hedgehog_x);

            for (int i = 0; i < 4; i++)
            {
                int next_hedgehog_y = cur_hedgehog_y + dir_y[i];
                int next_hedgehog_x = cur_hedgehog_x + dir_x[i];
                if (!validate(next_hedgehog_y, next_hedgehog_x))
                {
                    continue;
                }

                if (!visited_hedgehog[next_hedgehog_y][next_hedgehog_x] && checked_hedgehog[next_hedgehog_y][next_hedgehog_x] == 0 && forest[next_hedgehog_y][next_hedgehog_x] != 'X' && forest[next_hedgehog_y][next_hedgehog_x] != '*')
                {
                    q_hedgehog.push(make_pair(next_hedgehog_y, next_hedgehog_x));
                    visited_hedgehog[next_hedgehog_y][next_hedgehog_x] = true;
                    checked_hedgehog[next_hedgehog_y][next_hedgehog_x] = checked_hedgehog[cur_hedgehog_y][cur_hedgehog_x] + 1;
                    if (forest[next_hedgehog_y][next_hedgehog_x] == 'D')
                    {
                        printf("%d", checked_hedgehog[next_hedgehog_y][next_hedgehog_x]);
                        return 0;
                    }
                }
            }
        }
    }
    printf("KAKTUS\n");
    return 0;
}

int main()
{
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        cin >> forest[i];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (forest[i][j] == 'S')
            {
                start_y = i;
                start_x = j;
            }
            if (forest[i][j] == 'D')
            {
                goal_y = i;
                goal_x = j;
            }
            if (forest[i][j] == '*')
            {
                water.push_back(make_pair(i, j));
            }
        }
    }

    /* 디버그 */
    // printf("%d %d\n", start_y, start_x);
    // printf("%d %d\n", goal_y, goal_x);
    // printf("%d %d\n", water[0].first, water[0].second);

    bfs();

    return 0;
}