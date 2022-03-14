#include <cstdio>
#include <cstring>
#include <stack>

#define MAX 100001

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    char str[MAX];
    int cnt = 0;
    while (N--)
    {
        scanf("%s", str);
        int len = strlen(str);
        if (len % 2 == 1)
        {
            continue;
        }
        stack<int> s;
        for (int i = 0; i < len; i++)
        {
            if (s.empty())
            {
                s.push(str[i]);
            }
            else
            {
                if (str[i] == 'A')
                {
                    if (s.top() == 'A')
                    {
                        s.pop();
                    }
                    else
                    {
                        s.push(str[i]);
                    }
                }
                else
                {
                    if (s.top() == 'B')
                    {
                        s.pop();
                    }
                    else
                    {
                        s.push(str[i]);
                    }
                }
            }
        }
        if (s.empty())
        {
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}