#include <cstdio>
#include <cstring>
#define MAX 2000001

using namespace std;

int q[MAX];
int head = 0, tail = 0;

void push(int x)
{
    q[tail++] = x;
}

void pop()
{
    head++;
}

int size()
{
    return tail - head;
}

int front()
{
    if (size() == 0)
    {
        return -1;
    }
    else
    {
        return q[head];
    }
}

int back()
{
    if (size() == 0)
    {
        return -1;
    }
    else
    {
        return q[tail - 1];
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    char op[10];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", op);
        if (!strcmp(op, "push"))
        {
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (!strcmp(op, "front"))
        {
            printf("%d\n", front());
        }
        else if (!strcmp(op, "back"))
        {
            printf("%d\n", back());
        }
        else if (!strcmp(op, "size"))
        {
            printf("%d\n", size());
        }
        else if (!strcmp(op, "empty"))
        {
            if (size() == 0)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if (!strcmp(op, "pop"))
        {
            if (size() == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", front());
                pop();
            }
        }
    }
    return 0;
}