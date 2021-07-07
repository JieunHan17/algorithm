#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

/* 푸는 중 */
int n;
vector<pair<int, int> > coordinates;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        coordinates.push_back(make_pair(x, y));
    }
    return 0;
}