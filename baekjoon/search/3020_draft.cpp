#include <cstdio>
#include <iostream>

using namespace std;

int N, H, ans = 200000, cnt = 1;
int barrier[200000] = {
    0,
};

bool checkBottom(int idx, int bug)
{
    if (barrier[idx] >= bug)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkTop(int idx, int bug)
{
    if (barrier[idx] >= (H - bug + 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int fly(int bug)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            if (checkBottom(i, bug))
            {
                cnt++;
            }
        }
        else
        {
            if (checkTop(i, bug))
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    scanf("%d %d", &N, &H);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &barrier[i]);
    }

    for (int i = 0; i < H; i++)
    {
        int crash = fly(i);
        if (crash < ans)
        {
            ans = crash;
            cnt = 1;
        }
        else if (crash == ans)
        {
            cnt++;
        }
    }
    printf("%d %d", ans, cnt);
}