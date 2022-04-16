#include <cstdio>
#include <queue>
#include <utility>

#define MAX 51

using namespace std;

int R, C, T;
int A[MAX][MAX];
int dy[4] = {-1, 0, 1, 0}; // 북동남서
int dx[4] = {0, 1, 0, -1};

int main()
{
    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int sec = 0;
    while (sec < T)
    {
        /* 미세먼지가 있는 칸 저장 */
        queue<pair<pair<int, int>, int> > q;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (A[i][j] != 0 && A[i][j] != -1)
                {
                    q.push(make_pair(make_pair(i, j), A[i][j] / 5));
                }
            }
        }

        /* 1번 과정 */
        while (!q.empty())
        {
            int curY = q.front().first.first;
            int curX = q.front().first.second;
            int amount = q.front().second;
            q.pop();

            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int nextY = curY + dy[i];
                int nextX = curX + dx[i];
                if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
                {
                    continue;
                }
                if (A[nextY][nextX] == -1)
                {
                    continue;
                }
                A[nextY][nextX] += amount;
                cnt++;
            }
            A[curY][curX] -= (amount * cnt);
        }

        /* 2번 과정 */
        vector<int> robot;
        for (int i = 0; i < R; i++)
        {
            if (A[i][0] == -1)
            {
                robot.push_back(i);
            }
        }
        // 복사하기
        int A_copy[R][C];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                A_copy[i][j] = A[i][j];
            }
        }
        // 반시계 방향
        A_copy[robot[0]][1] = 0;
        for (int j = 2; j < C; j++)
        {
            A_copy[robot[0]][j] = A[robot[0]][j - 1];
        }
        for (int i = robot[0] - 1; i >= 0; i--)
        {
            A_copy[i][C - 1] = A[i + 1][C - 1];
        }
        for (int j = C - 2; j >= 0; j--)
        {
            A_copy[0][j] = A[0][j + 1];
        }
        for (int i = 1; i < robot[0]; i++)
        {
            A_copy[i][0] = A[i - 1][0];
        }
        // 시계 방향
        A_copy[robot[1]][1] = 0;
        for (int j = 2; j < C; j++)
        {
            A_copy[robot[1]][j] = A[robot[1]][j - 1];
        }
        for (int i = robot[1] + 1; i < R; i++)
        {
            A_copy[i][C - 1] = A[i - 1][C - 1];
        }
        for (int j = C - 2; j >= 0; j--)
        {
            A_copy[R - 1][j] = A[R - 1][j + 1];
        }
        for (int i = R - 2; i > robot[1]; i--)
        {
            A_copy[i][0] = A[i + 1][0];
        }
        // 붙여넣기
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                A[i][j] = A_copy[i][j];
            }
        }

        sec++;
    }

    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (A[i][j] != 0 && A[i][j] != -1)
            {
                ans += A[i][j];
            }
        }
    }

    printf("%d", ans);
    return 0;
}
// 시간 복잡도: 1000 * 50 * 50 = 2,500,000