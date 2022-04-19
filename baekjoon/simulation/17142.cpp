#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define MAX_N 51
#define MAX 98765

using namespace std;

int N, M;
int lab[MAX_N][MAX_N];
int lab_copy[MAX_N][MAX_N]; // 0: 활성 바이러스, -1: 비활성 바이러스, -2: 벽, -3: 빈칸
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int> > viruses;
int ans = MAX;

int bfs()
{
    queue<pair<int, int> > q;
    int empty = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (lab_copy[i][j] == 0)
            {
                q.push(make_pair(i, j));
            }
            else if (lab_copy[i][j] == -3)
            {
                empty++;
            }
        }
    }

    int result;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        if (empty == 0)
        {
            return result;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
            {
                continue;
            }
            if (lab_copy[nextY][nextX] == -2)
            {
                continue;
            }
            if (lab_copy[nextY][nextX] >= 0)
            {
                continue;
            }
            if (lab_copy[nextY][nextX] == -3)
            {
                empty--;
            }
            q.push(make_pair(nextY, nextX));
            lab_copy[nextY][nextX] = lab_copy[curY][curX] + 1;
            result = lab_copy[nextY][nextX];
        }
    }

    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);

    /* 입력 처리 */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int cell;
            scanf("%d", &cell);
            if (cell == 2)
            {
                viruses.push_back(make_pair(i, j));
            }
            else if (cell == 1)
            {
                lab[i][j] = -2;
            }
            else if (cell == 0)
            {
                lab[i][j] = -3;
            }
        }
    }

    /* 활성 바이러스 조합 */
    vector<int> v;
    for (int i = 0; i < M; i++)
    {
        v.push_back(0);
    }
    int sz = viruses.size();
    for (int i = M; i < sz; i++)
    {
        v.push_back(1);
    }
    do
    {
        bool isThereEmpty = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // 초기화
                lab_copy[i][j] = lab[i][j];
                if (lab_copy[i][j] == -3)
                {
                    isThereEmpty = true;
                }
            }
        }

        if (!isThereEmpty)
        {
            printf("0");
            return 0;
        }

        for (int i = 0; i < sz; i++)
        {
            if (v[i] == 0) // 활성 바이러스 체크
            {
                lab_copy[viruses[i].first][viruses[i].second] = 0;
            }
            else // 비활성 바이러스 체크
            {
                lab_copy[viruses[i].first][viruses[i].second] = -1;
            }
        }
        int result = bfs();
        if (result != -1)
        {
            ans = min(ans, result);
        } 
    } while (next_permutation(v.begin(), v.end()));
    
    if (ans == MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d", ans);
    }
    return 0;
}