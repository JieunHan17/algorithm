#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 1000000001
#define MIN -1000000001
#define MAX_SIZE 12

using namespace std;

int N;
int numbers[MAX_SIZE];
int operators[MAX_SIZE];
int combi[MAX_SIZE];

int getSum()
{
    int total = numbers[0];
    for (int i = 0; i < N - 1; i++)
    {
        if (combi[i] == 0)
        {
            total += numbers[i + 1];
        }
        else if (combi[i] == 1)
        {
            total -= numbers[i + 1];
        }
        else if (combi[i] == 2)
        {
            total *= numbers[i + 1];
        }
        else
        {
            total /= numbers[i + 1];
        }
    }
    return total;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &operators[i]);
    }

    vector<int> v;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < operators[i]; j++)
        {
            v.push_back(i);
        }
    }

    int maximum = MIN;
    int minimum = MAX;
    do
    {
        for (int i = 0; i < N - 1; i++)
        {
            combi[i] = v[i];
        }

        int result = getSum();
        maximum = max(maximum, result);
        minimum = min(minimum, result);
    } while (next_permutation(v.begin(), v.end()));
    
    printf("%d\n", maximum);
    printf("%d\n", minimum);

    return 0;
}