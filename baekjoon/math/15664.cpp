#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, C;
int input[8];
int output[8];
bool visited[8] = {
    false,
};

void pick(int cnt)
{
    if (cnt == M)
    {
        bool flag = false;
        for (int i = 0; i < M; i++)
        {
            if (output[i] > output[i + 1] && (i + 1) < M)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            for (int i = 0; i < M; i++)
            {
                printf("%d ", output[i]);
            }
            printf("\n");
            return;
        }
    }
    else
    {
        int prev = 0;
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && prev != input[i])
            {
                visited[i] = true;
                output[cnt] = input[i];
                prev = input[i];
                pick(cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
    }
    sort(input, input + N);
    pick(0);
    return 0;
}