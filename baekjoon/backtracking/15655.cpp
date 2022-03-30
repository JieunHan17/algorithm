#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 9
#define MAX_NUM 10001

using namespace std;

int N, M;
vector<int> input;
int isUsed[MAX_NUM];
int output[MAX];

void func(int K, int idx)
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
    for (int i = idx; i < N; i++)
    {
        if (!isUsed[input[i]])
        {
            isUsed[input[i]] = true;
            output[K] = input[i];
            func(K + 1, i);
            isUsed[input[i]] = false;
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

    func(0, 0);

    return 0;
}