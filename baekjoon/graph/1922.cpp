#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, total = 0, cnt = 0;
int parent[1001];
vector<pair<pair<int, int>, int> > input;

int my_find(int target)
{
    if (parent[target] == target)
    {
        return target;
    }
    else
    {
        return parent[target] = my_find(parent[target]);
    }
}

void my_union(int num1, int num2, int weight)
{
    int parent1 = my_find(num1);
    int parent2 = my_find(num2);

    if (parent1 > parent2)
    {
        parent[parent1] = parent2;
        total += weight;
        cnt++;
    }
    else if (parent1 < parent2)
    {
        parent[parent2] = parent1;
        total += weight;
        cnt++;
    }
}

bool compare(pair<pair<int, int>, int> input1, pair<pair<int, int>, int> input2)
{
    return input1.second < input2.second;
}

int main()
{
    int a, b, c;

    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        input.push_back(make_pair(make_pair(a, b), c));
    }
    sort(input.begin(), input.begin() + m, compare);

    for (int i = 0; i < m; i++)
    {
        if (cnt == n - 1)
        {
            break;
        }
        my_union(input[i].first.first, input[i].first.second, input[i].second);
    }
    printf("%d", total);

    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%d %d %d", &a, &b, &c);
    //     input[a].push_back(make_pair(b, c));
    //     input[b].push_back(make_pair(a, c));
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     sort(input[i].begin(), input[i].begin() + input[i].size(), compare);
    //     for (int j = 0; j < input[i].size(); j++)
    //     {
    //         printf("%d %d\n", input[i][j].first, input[i][j].second);
    //     }
    // }

    return 0;
}