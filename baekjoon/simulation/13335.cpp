#include <cstdio>
#include <queue>

#define MAX 11
#define MAX_LEN 101

using namespace std;

int n, w, L;
int loc[MAX_LEN];

bool isEmpty()
{
    for (int i = 0; i < w; i++)
    {
        if (loc[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d %d %d", &n, &w, &L);
    queue<int> rest;
    for (int i = 0; i < n; i++)
    {
        int truck;
        scanf("%d", &truck);
        rest.push(truck);
    }

    int ans = 0;
    do
    {
        int total = 0;
        for (int i = 0; i < w; i++)
        {
            total += loc[i];
        }

        if (total <= L)
        {
            total -= loc[w - 1];
            for (int i = w - 1; i > 0; i--)
            {
                loc[i] = loc[i - 1];
            }
            loc[0] = 0;

            if (!rest.empty() && (total + rest.front() <= L))
            {
                loc[0] = rest.front();
                rest.pop();
            }
        }
        ans++;
    } while (!isEmpty());
    
    printf("%d", ans);
    return 0;
}
