#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int k = 0;
int S[12] = {
    0,
};
int checked[12] = {
    0,
};
int arr[6] = {
    0,
};

int dfs(int start_index, int start_checked_value)
{
    checked[start_index] = start_checked_value;
    arr[checked[start_index] - 1] = S[start_index];

    for (int i = 1; i < (k - start_index); i++)
    {
        int next_index = start_index + i;

        if ((checked[start_index] + 1) <= 6)
        {
            dfs(next_index, checked[start_index] + 1);
            checked[next_index] = 0;
        }
    }

    if (arr[5] != 0)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    arr[checked[start_index] - 1] = 0;

    return 0;
}

int main()
{
    while (scanf("%d", &k) == 1)
    {
        if (k == 0)
        {
            return 0;
        }

        for (int i = 0; i < k; i++)
        {
            scanf("%d", &S[i]);
        }

        for (int i = 0; i <= (k - 6); i++)
        {
            dfs(i, 1);
        }
        printf("\n");
        fill(S, S + 12, 0);
    }

    return 0;
}