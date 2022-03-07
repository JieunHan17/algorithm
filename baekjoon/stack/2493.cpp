#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    stack<pair<int, int> > buildings;
    buildings.push(make_pair(100000001, 0));

    for (int i = 1; i <= N; i++)
    {
        int height;
        scanf("%d", &height);
        while (buildings.top().first < height)
        {
            buildings.pop();
        }
        printf("%d ", buildings.top().second);
        buildings.push(make_pair(height, i));
    }

    return 0;
}