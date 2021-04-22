#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int square_length = 0;
int dir_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dir_y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool visited[90000] = {
    false,
};
int checked[90000] = {
    0,
};

int bfs(int start_x, int start_y, int goal_x, int goal_y)
{
    queue<pair<int, int> > q;

    q.push(make_pair(start_x, start_y));
    visited[start_x + start_y * square_length] = true;

    if (start_x == goal_x && start_y == goal_y)
    {
        return 0;
    }

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int next_x = cur_x + dir_x[i];
            int next_y = cur_y + dir_y[i];

            if (!visited[next_x + next_y * square_length] && checked[next_x + next_y * square_length] == 0 && 0 <= next_x && next_x < square_length && 0 <= next_y && next_y < square_length)
            {
                q.push(make_pair(next_x, next_y));
                visited[next_x + next_y * square_length] = true;
                checked[next_x + next_y * square_length] = checked[cur_x + cur_y * square_length] + 1;
            }
        }
    }
    return checked[goal_x + goal_y * square_length];
}

int main()
{
    int test_case = 0;
    int start_x = 0;
    int start_y = 0;
    int goal_x = 0;
    int goal_y = 0;

    scanf("%d", &test_case);

    for (int i = 0; i < test_case; i++)
    {
        scanf("%d", &square_length);
        fill(visited, visited + square_length * square_length, false);
        fill(checked, checked + square_length * square_length, 0);
        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &goal_x, &goal_y);
        printf("%d\n", bfs(start_x, start_y, goal_x, goal_y));
    }

    return 0;
}