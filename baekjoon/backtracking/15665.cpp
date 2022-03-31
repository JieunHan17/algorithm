#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 8

using namespace std;

int N, M;
vector<int> input;
int output[MAX];

void func(int K)
{
    if (K == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }

    int prev = 0;
    for (int i = 0; i < N; i++)
    {
        if (prev != input[i])
        {
            output[K] = input[i];
            prev = input[i];
            func(K + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        input.push_back(num);
    }
    sort(input.begin(), input.end());

    func(0);
    return 0;
}