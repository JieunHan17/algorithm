#include <iostream>
#include <string>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string str;
        cin >> str;

        deque<int> dq;

        if (str.length() != 2)
        {
            int idx = 0;
            int start = 1;
            for (int i = 1; i < n; i++)
            {
                idx = str.find(',', start);
                dq.push_back(stoi(str.substr(start, idx - start)));
                start = idx + 1;
            }
            idx = str.find(']', start);
            dq.push_back(stoi(str.substr(start, idx - start)));
        }

        bool reverse = false;
        bool flag = true;
        queue<int> ans;
        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == 'R')
            {
                reverse = reverse ? false : true;
            }
            else if (p[i] == 'D')
            {
                if (dq.empty())
                {
                    printf("error\n");
                    flag = false;
                    break;
                }
                else
                {
                    if (reverse)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
            }
        }

        if (flag)
        {
            if (dq.empty())
            {
                printf("[]\n");
            }
            else
            {
                printf("[");
                while (dq.size() != 1)
                {
                    if (reverse)
                    {
                        printf("%d,", dq.back());
                        dq.pop_back();
                    }
                    else
                    {
                        printf("%d,", dq.front());
                        dq.pop_front();
                    }
                }
                printf("%d]\n", dq[0]);
                dq.pop_front();
            }
        }
    }
}