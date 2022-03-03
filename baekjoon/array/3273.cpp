#include <cstdio>
#define MAX 100001
#define MAX_VALUE 2000001

using namespace std;

int main()
{
    int n, x;
    int numbers[MAX];
    bool check[MAX_VALUE] = {
        false,
    };
    int ans = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
        check[numbers[i]] = true;
    }
    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] < x)
        {
            if (x - numbers[i] != numbers[i] && check[x - numbers[i]])
            {
                ans++;
                check[numbers[i]] = false;
            }
        }
    }
    printf("%d", ans);
    return 0;
}