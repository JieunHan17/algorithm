#include <cstdio>
#include <vector>
#include <utility>

#define MAX_N 51

using namespace std;

int N;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<pair<int, int>, int> > board[MAX_N][MAX_N]; // 질량(m), 속력(s), 방향(d)

int check(int num)
{
    if (num == 0)
    {
        return N;
    }
    else if (num == N + 1)
    {
        return 1;
    }
    else
    {
        return num;
    }
}

bool isOdd(int y, int x)
{
    bool flag = true;
    int sz = board[y][x].size();
    for (int i = 0; i < sz; i++)
    {
        if (board[y][x][i].second % 2 == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool isEven(int y, int x)
{
    bool flag = true;
    int sz = board[y][x].size();
    for (int i = 0; i < sz; i++)
    {
        if (board[y][x][i].second % 2 != 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int M, K;
    scanf("%d %d %d", &N, &M, &K);
    while (M--)
    {
        int r, c, m, s, d;
        scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
        board[r][c].push_back(make_pair(make_pair(m, s), d));
    }

    while (K--)
    {
        /* 1번 과정 */
        vector<pair<pair<int, int>, int> > board_copy[MAX_N][MAX_N];
        
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 0; k < board[i][j].size(); k++)
                {
                    int m = board[i][j][k].first.first;
                    int s = board[i][j][k].first.second;
                    int d = board[i][j][k].second;
                    
                    int curY = i;
                    int curX = j;
                    int move_limit = s % N;
                    for (int move = 0; move < move_limit; move++)
                    {
                        curY = check(curY + dy[d]);
                        curX = check(curX + dx[d]);
                    }
                    board_copy[curY][curX].push_back(make_pair(make_pair(m, s), d));
                }
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                board[i][j] = board_copy[i][j];
            }
        }

        /* 2번 과정 */
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (board[i][j].size() >= 2)
                {
                    int sz = board[i][j].size();
                    int total_m = 0;
                    int total_s = 0;
                    for (int k = 0; k < sz; k++)
                    {
                        total_m += board[i][j][k].first.first;
                        total_s += board[i][j][k].first.second;
                    }
                    int new_m = total_m / 5;
                    int new_s = total_s / sz;
                    vector<pair<pair<int, int>, int> > temp;
                    if (new_m != 0)
                    {
                        if (isOdd(i, j) || isEven(i, j))
                        {
                            // 0, 2, 4, 6
                            temp.push_back(make_pair(make_pair(new_m, new_s), 0));
                            temp.push_back(make_pair(make_pair(new_m, new_s), 2));
                            temp.push_back(make_pair(make_pair(new_m, new_s), 4));
                            temp.push_back(make_pair(make_pair(new_m, new_s), 6));
                        }
                        else
                        {
                            // 1, 3, 5, 7
                            temp.push_back(make_pair(make_pair(new_m, new_s), 1));
                            temp.push_back(make_pair(make_pair(new_m, new_s), 3));
                            temp.push_back(make_pair(make_pair(new_m, new_s), 5));
                            temp.push_back(make_pair(make_pair(new_m, new_s), 7));
                        }
                    }
                    board_copy[i][j] = temp;
                }
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
    

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < board[i][j].size(); k++)
            {
                ans += board[i][j][k].first.first;
            }
        }
    }
    printf("%d", ans);
    return 0;
}