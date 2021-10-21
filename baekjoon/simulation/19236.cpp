#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark
{
    int y;
    int x;
    int direction;
} shark;

struct Fish
{
    int y;
    int x;
    int direction;
} fish;

int direction[9][2] = {
    {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int maximum = 0;

vector<pair<int, int> > FindCandidateFish(vector<vector<pair<int, int> > > place)
{
    vector<pair<int, int> > candidateFish;
    int cur_y = shark.y;
    int cur_x = shark.x;

    while (1)
    {
        int next_y = cur_y + direction[shark.direction][0];
        int next_x = cur_x + direction[shark.direction][1];

        if (next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4)
        {
            break;
        }
        else if (place[next_y][next_x].first == 0)
        {
            cur_y = next_y;
            cur_x = next_x;
        }
        else
        {
            candidateFish.push_back(make_pair(next_y, next_x));
            cur_y = next_y;
            cur_x = next_x;
        }
    }
    return candidateFish;
}

void Solution(vector<vector<pair<int, int> > > place, vector<Fish> serialFish, int target_y, int target_x, int total)
{
    shark.y = target_y;
    shark.x = target_x;
    shark.direction = place[target_y][target_x].second;
    total += place[target_y][target_x].first;

    serialFish[place[target_y][target_x].first].y = -1;
    serialFish[place[target_y][target_x].first].x = -1;
    serialFish[place[target_y][target_x].first].direction = -1;

    place[target_y][target_x].first = -1;
    place[target_y][target_x].second = -1;

    /* Move Fish */
    for (int i = 1; i <= 16; i++)
    {
        int cur_y = serialFish[i].y;
        int cur_x = serialFish[i].x;
        int cur_direction = serialFish[i].direction;

        if (cur_y == -1)
        {
            continue;
        }

        int cntOfSpin = 0;
        while (1)
        {
            int next_y = cur_y + direction[cur_direction][0];
            int next_x = cur_x + direction[cur_direction][1];
            if (next_y == shark.y && next_x == shark.x || next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4)
            {
                cntOfSpin++;
                if (cntOfSpin >= 8)
                {
                    break;
                }
                if (cur_direction != 8)
                {
                    cur_direction++;
                }
                else
                {
                    cur_direction = 1;
                }
            }
            else
            {
                int next_num = place[next_y][next_x].first;
                place[cur_y][cur_x].second = cur_direction;
                swap(place[cur_y][cur_x], place[next_y][next_x]);

                serialFish[i].direction = cur_direction;
                if (next_num == 0)
                {
                    serialFish[i].y = next_y;
                    serialFish[i].x = next_x;
                }
                else
                {
                    swap(serialFish[i].y, serialFish[next_num].y);
                    swap(serialFish[i].x, serialFish[next_num].x);
                }

                break;
            }
        }
    }

    vector<pair<int, int> > candidateFish = FindCandidateFish(place);
    if (candidateFish.empty())
    {
        maximum = max(maximum, total);
        return;
    }

    place[shark.y][shark.x].first = 0;
    place[shark.y][shark.x].second = 0;
    for (int i = 0; i < candidateFish.size(); i++)
    {
        Solution(place, serialFish, candidateFish[i].first, candidateFish[i].second, total);
    }
}

int main()
{
    vector<vector<pair<int, int> > > place;
    for (int i = 0; i < 4; i++)
    {
        vector<pair<int, int> > v;
        for (int j = 0; j < 4; j++)
        {
            int num, dir;
            scanf("%d %d", &num, &dir);
            v.push_back(make_pair(num, dir));
        }
        place.push_back(v);
    }

    vector<Fish> serialFish(17);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Fish input = {i, j, place[i][j].second};
            serialFish[place[i][j].first] = input;
        }
    }

    Solution(place, serialFish, 0, 0, 0);

    printf("%d\n", maximum);

    return 0;
}