#include <cstdio>
#include <deque>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    deque<int> dq;
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    int idx[M];
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &idx[i]);

        deque<int> dq_front(dq);
        int cnt_front = 0;
        while (idx[i] != dq_front.front())
        {
            dq_front.push_back(dq_front.front());
            dq_front.pop_front();
            cnt_front++;
        }

        deque<int> dq_back(dq);
        int cnt_back = 0;
        while (idx[i] != dq_back.front())
        {
            dq_back.push_front(dq_back.back());
            dq_back.pop_back();
            cnt_back++;
        }

        if (cnt_front < cnt_back)
        {
            dq = dq_front;
            cnt += cnt_front;
        }
        else
        {
            dq = dq_back;
            cnt += cnt_back;
        }

        dq.pop_front();
    }

    printf("%d", cnt);

    return 0;
}