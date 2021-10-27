#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 20
#define MAX_M 401

using namespace std;

struct Shark
{
    int y;
    int x;
    int direction;
};

int N, M, K;
int dir_coordinates[5][2] = {
    {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int shark_priority[MAX_M][5][5] = {
    0,
};
Shark shark[MAX_M];
pair<int, int> place[MAX_N][MAX_N];

queue<pair<pair<int, int>, int> > CheckEmptyPlace(int shark_idx, int cur_y, int cur_x, int cur_direction)
{
    queue<pair<pair<int, int>, int> > q;

    for (int i = 1; i <= 4; i++)
    {
        int next_y = cur_y + dir_coordinates[shark_priority[shark_idx][cur_direction][i]][0];
        int next_x = cur_x + dir_coordinates[shark_priority[shark_idx][cur_direction][i]][1];
        if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
        {
            continue;
        }
        if (place[next_y][next_x].first == 0)
        {
            q.push(make_pair(make_pair(next_y, next_x), shark_priority[shark_idx][cur_direction][i]));
        }
    }
    return q;
}

queue<pair<pair<int, int>, int> > CheckMyScentPlace(int shark_idx, int cur_y, int cur_x, int cur_direction)
{
    queue<pair<pair<int, int>, int> > q;

    for (int i = 1; i <= 4; i++)
    {
        int next_y = cur_y + dir_coordinates[shark_priority[shark_idx][cur_direction][i]][0];
        int next_x = cur_x + dir_coordinates[shark_priority[shark_idx][cur_direction][i]][1];
        if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
        {
            continue;
        }
        if (place[next_y][next_x].first == place[cur_y][cur_x].first)
        {
            q.push(make_pair(make_pair(next_y, next_x), shark_priority[shark_idx][cur_direction][i]));
        }
    }
    return q;
}

int main()
{
    /* Input */
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            scanf("%d", &input);
            if (input != 0)
            {
                place[i][j] = make_pair(input, K);
                shark[input].y = i;
                shark[input].x = j;
            }
            else
            {
                place[i][j] = make_pair(input, 0);
            }
        }
    }

    for (int i = 1; i <= M; i++)
    {
        scanf("%d", &shark[i].direction);
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                scanf("%d", &shark_priority[i][j][k]);
            }
        }
    }

    /* Solution */
    int total_time = 0;
    int shark_cnt = M;

    while (total_time < 1000)
    {
        // Find the places that the shark can go
        queue<pair<pair<int, int>, int> > empty_places[MAX_M];
        queue<pair<pair<int, int>, int> > my_scent_places[MAX_M];

        for (int i = 1; i <= M; i++)
        {
            if (shark[i].y == -1)
            {
                continue;
            }

            int cur_y = shark[i].y;
            int cur_x = shark[i].x;

            empty_places[i] = CheckEmptyPlace(i, cur_y, cur_x, shark[i].direction);
            my_scent_places[i] = CheckMyScentPlace(i, cur_y, cur_x, shark[i].direction);
        }

        // Move every shark
        vector<pair<int, int> > exception_from_removing;
        for (int i = 1; i <= M; i++)
        {
            if (shark[i].y == -1)
            {
                continue;
            }

            if (empty_places[i].empty())
            {
                if (!my_scent_places[i].empty())
                {
                    place[my_scent_places[i].front().first.first][my_scent_places[i].front().first.second].second = K;
                    shark[i].y = my_scent_places[i].front().first.first;
                    shark[i].x = my_scent_places[i].front().first.second;
                    shark[i].direction = my_scent_places[i].front().second;
                    exception_from_removing.push_back(make_pair(shark[i].y, shark[i].x));
                }
            }
            else
            {
                if (place[empty_places[i].front().first.first][empty_places[i].front().first.second].first == 0)
                {
                    place[empty_places[i].front().first.first][empty_places[i].front().first.second].first = i;
                    place[empty_places[i].front().first.first][empty_places[i].front().first.second].second = K;
                    shark[i].y = empty_places[i].front().first.first;
                    shark[i].x = empty_places[i].front().first.second;
                    shark[i].direction = empty_places[i].front().second;
                    exception_from_removing.push_back(make_pair(shark[i].y, shark[i].x));
                }
                else
                {
                    shark[i].y = -1;
                    shark[i].x = -1;
                    shark[i].direction = -1;
                    shark_cnt--;
                }
            }
        }

        // Decrease the scent
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (place[i][j].second > 0)
                {
                    place[i][j].second--;
                }
            }
        }

        // Restore the scent
        for (int i = 0; i < exception_from_removing.size(); i++)
        {
            place[exception_from_removing[i].first][exception_from_removing[i].second].second = K;
        }

        // Remove the scent
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (place[i][j].second == 0)
                {
                    place[i][j].first = 0;
                }
            }
        }

        total_time++;

        if (shark_cnt == 1)
        {
            printf("%d\n", total_time);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}