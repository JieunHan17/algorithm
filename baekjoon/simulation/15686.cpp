// 시간 복잡도: 13 * 100 * 13 = 19,600

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define MAX 51
#define MAX_DIST 98765

using namespace std;

int N, M;
int city[MAX][MAX];
vector<pair<int, int> > homes;
vector<pair<int, int> > chickens;

int getDistToChicken(int startY, int startX, vector<int> selected)
{
    int result = MAX_DIST;
    for (int i = 0; i < M; i++)
    {
        int chickenY = chickens[selected[i]].first;
        int chickenX = chickens[selected[i]].second;

        result = min(result, abs(startY - chickenY) + abs(startX - chickenX));
    }
    return result;
}

int main()
{   
    scanf("%d %d", &N, &M);

    int cntOfChickens = 0; // 총 치킨집의 수
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &city[i][j]);
            if (city[i][j] == 1)
            {
                homes.push_back(make_pair(i, j));
            }
            else if (city[i][j] == 2)
            {
                chickens.push_back(make_pair(i, j));
                cntOfChickens++;
            }
        }
    }

    vector<int> temp;
    for (int i = 0; i < M; i++)
    {
        temp.push_back(0);
    }
    for (int i = M; i < cntOfChickens; i++)
    {
        temp.push_back(1);
    }

    int ans = MAX_DIST;
    do
    {
        vector<int> selected;
        for (int i = 0; i < cntOfChickens; i++)
        {
            if (temp[i] == 0)
            {
                selected.push_back(i);
            }
        }

        int dist = 0;
        for (int i = 0; i < homes.size(); i++)
        {
            dist += getDistToChicken(homes[i].first, homes[i].second, selected);
        }

        ans = min(ans, dist);
    } while (next_permutation(temp.begin(), temp.end()));
    
    printf("%d", ans);
    return 0;
}