#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX 101

using namespace std;

int r, c, k;
int A[MAX][MAX];

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%d %d %d", &r, &c, &k);
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int row = 3, col = 3;
    int time = 0;
    while (1)
    {
        if (A[r][c] == k)
        {
            printf("%d", time);
            break;
        }

        if (time == 100)
        {
            printf("-1");
            break;
        }

        /* R 연산 */
        if (row >= col)
        {
            for (int i = 1; i <= row; i++)
            {
                int cnt[MAX] = {};
                int zeros = 0;
                for (int j = 1; j <= col; j++)
                {
                    if (A[i][j] == 0)
                    {
                        zeros++;
                    }
                    else
                    {
                        cnt[A[i][j]]++;
                    }
                }
                vector<pair<int, int> > v;
                for (int idx = 1; idx < MAX; idx++)
                {
                    if (cnt[idx] > 0)
                    {
                        v.push_back(make_pair(idx, cnt[idx]));
                    }
                }
                sort(v.begin(), v.end(), compare);

                int sz = v.size();
                if (sz * 2 > 100)
                {
                    col = 100;
                }
                else
                {
                    col = max(col, sz * 2);
                }

                int curCol = 1;
                for (int idx = 0; idx < sz; idx++)
                {
                    A[i][curCol] = v[idx].first;
                    A[i][curCol + 1] = v[idx].second;
                    curCol += 2;
                }
                for (int j = curCol; j <= col; j++)
                {
                    A[i][j] = 0;
                }
            }
        }

        /* C 연산 */
        else
        {
            for (int j = 1; j <= col; j++)
            {
                int cnt[MAX] = {};
                int zeros = 0;
                for (int i = 1; i <= row; i++)
                {
                    if (A[i][j] == 0)
                    {
                        zeros++;
                    }
                    else
                    {
                        cnt[A[i][j]]++;
                    }
                }
                vector<pair<int, int> > v;
                for (int idx = 1; idx < MAX; idx++)
                {
                    if (cnt[idx] > 0)
                    {
                        v.push_back(make_pair(idx, cnt[idx]));
                    }
                }
                sort(v.begin(), v.end(), compare);

                int sz = v.size();
                if (sz * 2 > 100)
                {
                    row = 100;
                }
                else
                {
                    row = max(row, sz * 2);
                }

                int curRow = 1;
                for (int idx = 0; idx < sz; idx++)
                {
                    A[curRow][j] = v[idx].first;
                    A[curRow + 1][j] = v[idx].second;
                    curRow += 2;
                }
                for (int i = curRow; i <= row; i++)
                {
                    A[i][j] = 0;
                }
            }
        }

        time++;
    }

    return 0;
}