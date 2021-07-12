#include <cstdio>
#include <vector>

using namespace std;

int N, M;
int output[9];
bool visited[9];

void pick(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                output[cnt] = i;
                pick(cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    pick(0);
    return 0;
}