#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 11

using namespace std;

struct SHARK_MOVE
{
    vector<int> directions;
    int cntOfFish;
};

int M, S;
int board_smell[5][5]; // 0: 없음
vector<pair<int, int> > board_fish[5][5];
vector<pair<int, int> > board_fish_copy[5][5];
int sharkY, sharkX;

int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dirToNum[4] = {1, 2, 3, 4}; // 상, 좌, 하, 우
int dirY[4] = {-1, 0, 1, 0};
int dirX[4] = {0, -1, 0, 1};

void duplicateStart()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            board_fish_copy[i][j] = board_fish[i][j];
        }
    }
}

void moveFish()
{
    vector<pair<int, int> > temp[5][5];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (!board_fish[i][j].empty())
            {
                for (int k = 0; k < board_fish[i][j].size(); k++)
                {
                    int curY = i;
                    int curX = j;
                    int curFish = board_fish[i][j][k].first;
                    int curDir = board_fish[i][j][k].second;
                    bool isMoved = false;
                    for (int l = 0; l < 8; l++)
                    {
                        int nextY = curY + dy[curDir];
                        int nextX = curX + dx[curDir];
                        if (nextY == sharkY && nextX == sharkX || board_smell[nextY][nextX] > 0 || nextY < 1 || nextY > 4 || nextX < 1 || nextX > 4)
                        {
                            curDir = (curDir + 7) % 8;
                            if (curDir == 0)
                            {
                                curDir = 8;
                            }
                            continue;
                        }
                        else
                        {
                            isMoved = true;
                            temp[nextY][nextX].push_back(make_pair(curFish, curDir));
                            break;
                        }
                    }
                    if (!isMoved)
                    {
                        temp[curY][curX].push_back(make_pair(curFish, curDir));
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            board_fish[i][j] = temp[i][j];
        }
    }
}

bool compare(SHARK_MOVE input1, SHARK_MOVE input2)
{
    if (input1.cntOfFish > input2.cntOfFish)
    {
        return true;
    }
    else if (input1.cntOfFish == input2.cntOfFish)
    {
        for (int i = 0; i < 3; i++)
        {
            if (dirToNum[input1.directions[i]] < dirToNum[input2.directions[i]])
            {
                return true;
            }
            else if (dirToNum[input1.directions[i]] == dirToNum[input2.directions[i]])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    else
    {
        return false;
    }
}

void moveShark(int step)
{
    vector<SHARK_MOVE> v_shark_move;
    SHARK_MOVE shark_move;
    for (int temp = 0; temp < (1<<(2*3)); temp++)
    {
        int brute = temp;
        
        int cntOfFish = 0;
        vector<int> directions;

        int curY = sharkY;
        int curX = sharkX;

        bool eaten[5][5] = {false,};

        bool isAble = true;
        for (int i = 0; i < 3; i++)
        {
            int dir = brute % 4;
            brute /= 4;

            int nextY = curY + dirY[dir];
            int nextX = curX + dirX[dir];
            if (nextY < 1 || nextY > 4 || nextX < 1 || nextX > 4)
            {
                isAble = false;
                break;
            }
            directions.push_back(dir);
            if (!board_fish[nextY][nextX].empty() && !eaten[nextY][nextX])
            {
                cntOfFish += board_fish[nextY][nextX].size();
                eaten[nextY][nextX] = true;
            }
            curY = nextY;
            curX = nextX;
        }
        if (isAble)
        {
            shark_move.cntOfFish = cntOfFish;
            shark_move.directions = directions;
            v_shark_move.push_back(shark_move);
        }
    }
    sort(v_shark_move.begin(), v_shark_move.end(), compare);

    int curY = sharkY;
    int curX = sharkX;
    for (int i = 0; i < 3; i++)
    {
        int dir = v_shark_move[0].directions[i];
        curY += dirY[dir];
        curX += dirX[dir];
        if (!board_fish[curY][curX].empty())
        {
            vector<pair<int, int> > empty;
            board_fish[curY][curX] = empty;
            board_smell[curY][curX] = step;
        }
    }
    sharkY = curY;
    sharkX = curX;
}

void removeSmell(int step)
{
    if (step <= 2)
    {
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (board_smell[i][j] == step - 2)
            {
                board_smell[i][j] = 0;
            }
        }
    }
}

void duplicateFinish()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (!board_fish_copy[i][j].empty())
            {
                for (int k = 0; k < board_fish_copy[i][j].size(); k++)
                {
                    int curFish = board_fish_copy[i][j][k].first;
                    int curDir = board_fish_copy[i][j][k].second;
                    board_fish[i][j].push_back(make_pair(curFish, curDir));
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &M, &S);
    for (int i = 1; i <= M; i++)
    {
        int fishY, fishX, d;
        scanf("%d %d %d", &fishY, &fishX, &d);
        board_fish[fishY][fishX].push_back(make_pair(i, d));
    }
    scanf("%d %d", &sharkY, &sharkX);

    for (int i = 1; i <= S; i++)
    {
        duplicateStart();
        moveFish();
        moveShark(i);
        removeSmell(i);
        duplicateFinish();
    }

    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (!board_fish[i][j].empty())
            {
                ans += board_fish[i][j].size();
            }
        }
    }
    printf("%d", ans);
    return 0;
}