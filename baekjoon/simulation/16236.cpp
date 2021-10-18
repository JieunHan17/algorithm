#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX 20

using namespace std;

typedef struct
{
    int y;
    int x;
    int size;
    int eaten_fish;
    int total_time;
} Shark;

int N;
int place[20][20] = {
    0,
};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
Shark shark;

bool compare(pair<int, pair<int, int> > fish1, pair<int, pair<int, int> > fish2)
{
    if (fish1.first != fish2.first)
    {
        return fish1.first < fish2.first;
    }
    else if (fish1.second.first != fish2.second.first)
    {
        return fish1.second.first < fish2.second.first;
    }
    else
    {
        return fish1.second.second < fish2.second.second;
    }
}

vector<pair<int, pair<int, int> > > BFS(int start_y, int start_x)
{
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(start_y, start_x), 0));

    bool visited[MAX][MAX] = {
        false,
    };
    visited[start_y][start_x] = true;

    vector<pair<int, pair<int, int> > > fish;
    while (!q.empty())
    {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int cur_move_cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            int next_move_cnt = cur_move_cnt + 1;
            if (visited[next_y][next_x] || next_y < 0 || N - 1 < next_y || next_x < 0 || N - 1 < next_x)
            {
                continue;
            }
            if (place[next_y][next_x] <= shark.size)
            {
                q.push(make_pair(make_pair(next_y, next_x), next_move_cnt));
                visited[next_y][next_x] = true;
                if (place[next_y][next_x] < shark.size && place[next_y][next_x] != 0)
                {
                    fish.push_back(make_pair(next_move_cnt, make_pair(next_y, next_x)));
                }
            }
        }
    }

    return fish;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &place[i][j]);
            if (place[i][j] == 9)
            {
                shark.y = i;
                shark.x = j;
                place[i][j] = 0;
            }
        }
    }

    shark.total_time = 0;
    shark.size = 2;
    shark.eaten_fish = 0;

    while (1)
    {
        vector<pair<int, pair<int, int> > > fish = BFS(shark.y, shark.x);
        if (!fish.empty())
        {
            sort(fish.begin(), fish.end(), compare);

            shark.y = fish[0].second.first;
            shark.x = fish[0].second.second;
            shark.eaten_fish++;
            shark.total_time += fish[0].first;
            place[shark.y][shark.x] = 0;

            if (shark.eaten_fish == shark.size)
            {
                shark.size++;
                shark.eaten_fish = 0;
            }
        }
        else
        {
            break;
        }
    }

    printf("%d\n", shark.total_time);

    return 0;
}