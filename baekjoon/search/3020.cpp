#include <cstdio>
#include <iostream>

using namespace std;

int N, H, ans = 200000, cnt = 1;
int barrier[200000] = {
    0,
};
int height[500000] = {
    0,
};

int main()
{
    scanf("%d %d", &N, &H);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &barrier[i]);
        if (i % 2 == 0)
        {
            height[0]++;
            height[barrier[i]]--;
        }
        else
        {
            //종유석 방향 반대 주의
            height[H - barrier[i]]++;
        }
    }

    for (int i = 0; i < H; i++)
    {
        height[i] += height[i - 1];
        if (height[i] < ans)
        {
            ans = height[i];
            cnt = 1;
        }
        else if (height[i] == ans)
        {
            cnt++;
        }
    }
    printf("%d %d", ans, cnt);
}