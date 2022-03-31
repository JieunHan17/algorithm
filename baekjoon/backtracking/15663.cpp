#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
vector<int> input;
int output[MAX];
bool isUsed[MAX];

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
        if (!isUsed[i] && prev != input[i])
        {
            isUsed[i] = true;
            output[K] = input[i];
            prev = input[i];
            func(K + 1);
            isUsed[i] = false;
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