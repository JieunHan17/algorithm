#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 101

using namespace std;

char pic[MAX][MAX];
bool visited[MAX][MAX];
bool visited_problem[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> pic[i];
    }

    for (int i = 0; i < N; i++)
    {
        fill(visited[i], visited[i] + N, false);
        fill(visited_problem[i], visited_problem[i] + N, false);
    }

    queue<pair<int, int> > q;
    queue<pair<int, int> > q_problem;
    int cnt_normal = 0;
    int cnt_problem = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                cnt_normal++;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nextY = curY + dy[i];
                        int nextX = curX + dx[i];
                        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                        {
                            continue;
                        }
                        if (!visited[nextY][nextX] && pic[nextY][nextX] == pic[curY][curX])
                        {
                            q.push(make_pair(nextY, nextX));
                            visited[nextY][nextX] = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited_problem[i][j])
            {
                cnt_problem++;
                q_problem.push(make_pair(i, j));
                while (!q_problem.empty())
                {
                    int curY = q_problem.front().first;
                    int curX = q_problem.front().second;
                    q_problem.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nextY = curY + dy[i];
                        int nextX = curX + dx[i];
                        if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                        {
                            continue;
                        }
                        if (!visited_problem[nextY][nextX] && (pic[nextY][nextX] == pic[curY][curX] || pic[nextY][nextX] == 'R' && pic[curY][curX] == 'G' || pic[nextY][nextX] == 'G' && pic[curY][curX] == 'R'))
                        {
                            q_problem.push(make_pair(nextY, nextX));
                            visited_problem[nextY][nextX] = true;
                        }
                    }
                }
            }
        }
    }

    cout << cnt_normal << " " << cnt_problem;

    return 0;
}