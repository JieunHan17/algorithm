#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    stack<int> num;
    queue<char> ans;

    int numbers[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 1; i <= numbers[0]; i++)
    {
        num.push(i);
        ans.push('+');
    }
    int maximum = num.top();

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > maximum)
        {
            for (int j = maximum + 1; j <= numbers[i]; j++)
            {
                num.push(j);
                ans.push('+');
            }
            maximum = num.top();
            i--;
        }
        else
        {
            if (numbers[i] == num.top())
            {
                num.pop();
                ans.push('-');
            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    while (!ans.empty())
    {
        printf("%c\n", ans.front());
        ans.pop();
    }

    return 0;
}