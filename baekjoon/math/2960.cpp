#include <cstdio>

using namespace std;

int main()
{
    int N, K;
    int reseto[1001] = {0, 1};
    int cnt = 0;

    scanf("%d %d", &N, &K);

    for (int i = 2; i <= N; i++)
    {
        if (reseto[i] != 1)
        {
            for (int j = i; j <= N; j += i)
            {
                if (reseto[j] != 1)
                {
                    cnt++;
                    reseto[j] = 1;
                    if (cnt == K)
                    {
                        printf("%d", j);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}