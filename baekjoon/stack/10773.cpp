#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int K;
    scanf("%d", &K);

    stack<int> s;
    for (int i = 0; i < K; i++)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
        {
            s.pop();
        }
        else
        {
            s.push(num);
        }
    }

    int ans = 0;
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }

    printf("%d", ans);
    return 0;
}