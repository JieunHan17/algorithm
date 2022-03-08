#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    int last;
    while (!q.empty())
    {
        last = q.front();
        q.pop();

        if (!q.empty())
        {
            q.push(q.front());
            q.pop();
        }
    }

    printf("%d", last);

    return 0;
}