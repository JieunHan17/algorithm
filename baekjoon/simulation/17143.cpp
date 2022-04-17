#include <cstdio>
#include <unordered_map>

#define MAX 101

using namespace std;

int R, C, M;
pair<pair<int, int>, int> ground[MAX][MAX];
pair<pair<int, int>, int> ground_copy[MAX][MAX];
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};
unordered_map<int, int> opposite_dir;

int main()
{
    opposite_dir[1] = 2;
    opposite_dir[2] = 1;
    opposite_dir[3] = 4;
    opposite_dir[4] = 3;

    scanf("%d %d %d", &R, &C, &M);
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        ground[r][c] = make_pair(make_pair(s, d), z);
    }

    int ans = 0;
    for (int j = 1; j <= C; j++)
    {
        /* 2번 과정 */
        for (int i = 1; i <= R; i++)
        {
            if (ground[i][j].second != 0)
            {
                // 상어가 존재
                ans += ground[i][j].second;
                ground[i][j] = make_pair(make_pair(0, 0), 0);
                M--;
                break;
            }
        }

        /* 3번 과정 */
        for (int row = 1; row <= R; row++)
        {
            for (int col = 1; col <= C; col++)
            {
                ground_copy[row][col] = make_pair(make_pair(0, 0), 0);
            }
        }
        for (int row = 1; row <= R; row++)
        {
            for (int col = 1; col <= C; col++)
            {
                if (ground[row][col].second != 0)
                {
                    int curY = row;
                    int curX = col;
                    int velocity = ground[row][col].first.first;
                    int dir = ground[row][col].first.second;
                    int size = ground[row][col].second;
                    
                    int mod = dir == 1 || dir == 2 ? velocity % ((R - 1) * 2) : velocity % ((C - 1) * 2);
                    for (int move = 0; move < mod; move++)
                    {
                        int nextY = curY + dy[dir];
                        int nextX = curX + dx[dir];
                        if (nextY < 1 || nextY > R || nextX < 1 || nextX > C)
                        {
                            dir = opposite_dir[dir];
                            move--;
                        }
                        else
                        {
                            curY = nextY;
                            curX = nextX;
                        }
                    }

                    if (ground_copy[curY][curX].second < size)
                    {
                        ground_copy[curY][curX] = make_pair(make_pair(velocity, dir), size);
                    }
                }
            }
        }
        for (int row = 1; row <= R; row++)
        {
            for (int col = 1; col <= C; col++)
            {
                ground[row][col] = ground_copy[row][col];
            }
        }
    }

    printf("%d", ans);
    return 0;
}