#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

void addNode(int num)
{
    pq.push(num);
    return;
}

void printNode()
{
    if (pq.empty())
    {
        printf("0\n");
        return;
    }
    printf("%d\n", pq.top());
    pq.pop();
    return;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 0)
        {
            printNode();
        }
        else
        {
            addNode(x);
        }
    }
    return 0;
}