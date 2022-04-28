#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX_N 101
#define MAX_K 201

using namespace std;

int N, K;
int A[MAX_N * 2];
int belt[MAX_N * 2];

void moveBelt()
{
    int belt_copy[MAX_N * 2] = {0, };
    fill(belt_copy, belt_copy + N * 2 + 1, 0);

    int A_copy[MAX_N * 2];
    for (int i = 1; i <= N * 2; i++)
    {
        A_copy[i] = A[i];
    }

    for (int i = 1; i <= N * 2; i++)
    {
        if (i == N * 2)
        {
            belt_copy[1] = belt[i];
            A_copy[1] = A[i];
        }
        else
        {
            belt_copy[i + 1] = belt[i];
            A_copy[i + 1] = A[i];
        }
    }

    for (int i = 1; i <= N * 2; i++)
    {
        belt[i] = belt_copy[i];
        A[i] = A_copy[i];
    }
}

void takeOutRobot()
{
    if (belt[N] > 0)
    {
        belt[N] = 0;
    }
}

void moveRobots()
{
    vector<pair<int, int> > v;
    for (int i = 1; i <= N * 2; i++)
    {
        if (belt[i] > 0)
        {
            v.push_back(make_pair(belt[i], i));
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        int cur_loc = v[i].second;
        int next_loc = cur_loc == N * 2 ? 1 : cur_loc + 1;
        if (belt[next_loc] == 0 && A[next_loc] >= 1)
        {
            belt[next_loc] = belt[cur_loc];
            A[next_loc]--;
            belt[cur_loc] = 0;
        }
    }
}

void putRobot(int step)
{
    if (belt[1] == 0 && A[1] >= 1)
    {
        belt[1] = step;
        A[1]--;
    }
}

bool checkEscape()
{
    int cnt = 0;
    for (int i = 1; i <= N * 2; i++)
    {
        if (A[i] == 0)
        {
            cnt++;
        }
    }
    if (cnt >= K)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N * 2; i++)
    {
        scanf("%d", &A[i]);
    }

    int step = 1;
    while (1)
    {
        moveBelt();
        takeOutRobot();
        moveRobots();
        takeOutRobot();
        putRobot(step);
        bool stop = checkEscape();
        if (stop)
        {
            break;
        }
        step++;
    }
    printf("%d", step);
    return 0;
}