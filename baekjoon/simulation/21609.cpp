#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define MAX_N 21

using namespace std;

struct BLOCK_GROUP{
    int sz;
    int rainbow;
    int standardY;
    int standardX;
    vector<pair<int, int> > visitedBlocks;
};

int N, M;
int board[MAX_N][MAX_N]; // -2: 빈칸, -1: 검은색, 0: 무지개
int dy[4] = {-1, 0, 1, 0}; // 북동남서
int dx[4] = {0, 1, 0, -1};
int score = 0;

bool compare1(pair<int, int> block1, pair<int, int> block2)
{
    if (block1.first < block2.first)
    {
        return true;
    }
    else if (block1.first == block2.first)
    {
        return block1.second < block2.second;
    }
    else
    {
        return false;
    }
}

bool compare2(BLOCK_GROUP block1, BLOCK_GROUP block2)
{
    if (block1.sz > block2.sz)
    {
        return true;
    }
    else if (block1.sz == block2.sz)
    {
        if (block1.rainbow > block2.rainbow)
        {
            return true;
        }
        else if (block1.rainbow == block2.rainbow)
        {
            if (block1.standardY > block2.standardY)
            {
                return true;
            }
            else if (block1.standardY == block2.standardY)
            {
                return block1.standardX > block2.standardX;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

BLOCK_GROUP findBiggestGroup()
{
    vector<BLOCK_GROUP> v;
    bool visited[MAX_N][MAX_N] = {false, };

    vector<pair<int, int> > rainbows;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j] == 0)
            {
                rainbows.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!visited[i][j] && board[i][j] > 0)
            {
                BLOCK_GROUP block_group;

                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited[i][j] = true;

                int sz = 0;
                int rainbow = 0;
                bool isThereNormalBlock = board[i][j] > 0 ? true : false;
                int normal = board[i][j];
                vector<pair<int, int> > visitedBlocks;
                vector<pair<int, int> > normalBlocks;
                while (!q.empty())
                {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();
                    sz++;
                    visitedBlocks.push_back(make_pair(curY, curX));

                    if (board[curY][curX] > 0)
                    {
                        normalBlocks.push_back(make_pair(curY, curX));
                    }

                    for (int k = 0; k < 4; k++)
                    {
                        int nextY = curY + dy[k];
                        int nextX = curX + dx[k];
                        if (nextY < 1 || nextY > N || nextX < 1 || nextX > N)
                        {
                            continue;
                        }
                        if (!visited[nextY][nextX] && board[nextY][nextX] >= 0)
                        {
                            if (board[nextY][nextX] == 0)
                            {
                                rainbow++;
                                q.push(make_pair(nextY, nextX));
                                visited[nextY][nextX] = true;
                            }
                            else if (board[nextY][nextX] > 0)
                            {
                                if (isThereNormalBlock)
                                {
                                    if (board[nextY][nextX] != normal)
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        q.push(make_pair(nextY, nextX));
                                        visited[nextY][nextX] = true;
                                    }
                                }
                                else
                                {
                                    isThereNormalBlock = true;
                                    normal = board[nextY][nextX];
                                    q.push(make_pair(nextY, nextX));
                                    visited[nextY][nextX] = true;
                                }
                            }
                        }
                    }
                }
                if (!isThereNormalBlock)
                {
                    continue;
                }
                if (sz < 2)
                {
                    continue;
                }

                sort(normalBlocks.begin(), normalBlocks.end(), compare1);

                block_group.sz = sz;
                block_group.rainbow = rainbow;
                block_group.standardY = normalBlocks[0].first;
                block_group.standardX = normalBlocks[0].second;
                block_group.visitedBlocks = visitedBlocks;

                v.push_back(block_group);

                for (int k = 0; k < rainbows.size(); k++)
                {
                    // 그 다음 블록 그룹을 찾을 때 무지개 블록은 또 사용될 수 있음
                    visited[rainbows[k].first][rainbows[k].second] = false;
                }
            }
        }
    }
    sort(v.begin(), v.end(), compare2);

    if (v.empty())
    {
        BLOCK_GROUP block_group;
        block_group.sz = 0;
        return block_group;
    }

    return v[0];
}

void removeBlocks(BLOCK_GROUP biggest)
{
    for (int i = 0; i < biggest.sz; i++)
    {
        board[biggest.visitedBlocks[i].first][biggest.visitedBlocks[i].second] = -2;
    }
    score += (biggest.sz * biggest.sz);
}

void gravity()
{
    int temp[N + 1];
    for (int j = 1; j <= N; j++)
    {
        int empty = N;
        for (int i = N; i > 0; i--)
        {
            temp[i] = board[i][j];
            if (board[i][j] == -1)
            {
                if (i == 1)
                {
                    break;
                }
                else
                {
                    empty = i - 1;
                }
            }
            else if (board[i][j] >= 0)
            {
                temp[empty] = board[i][j];
                if (empty != i)
                {
                    temp[i] = -2;
                }
                empty--;
            }
        }

        for (int i = N; i > 0; i--)
        {
            board[i][j] = temp[i];
        }
    }
}

void rotateBoard()
{
    int board_copy[MAX_N][MAX_N];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            board_copy[N - j + 1][i] = board[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            board[i][j] = board_copy[i][j];
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    while (1) 
    {
        BLOCK_GROUP biggest = findBiggestGroup();
        if (biggest.sz == 0)
        {
            break;
        }
        removeBlocks(biggest);
        gravity();
        rotateBoard();
        gravity();
    }
    printf("%d", score);
    return 0;
}