#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char change(char cur)
{
    if (cur == '0')
    {
        return '1';
    }
    else
    {
        return '0';
    }
}

int pressFirst(int N, string current, string goal)
{
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            current[i] = change(current[i]);
            current[i + 1] = change(current[i + 1]);
            cnt++;
        }
        else
        {
            if (current[i - 1] != goal[i - 1])
            {
                current[i] = change(current[i]);
                current[i - 1] = change(current[i - 1]);
                if (i != N - 1)
                {
                    current[i + 1] = change(current[i + 1]);
                }
                cnt++;
            }
        }

        if (current == goal)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        return cnt;
    }
    else
    {
        return -1;
    }
}

int notPressFirst(int N, string current, string goal)
{
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
        {
            if (current[i - 1] != goal[i - 1])
            {
                current[i] = change(current[i]);
                current[i - 1] = change(current[i - 1]);
                if (i != N - 1)
                {
                    current[i + 1] = change(current[i + 1]);
                }
                cnt++;
            }
        }

        if (current == goal)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        return cnt;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N;
    string current, goal;
    cin >> N >> current >> goal;

    int cnt;
    int cnt1 = pressFirst(N, current, goal);
    int cnt2 = notPressFirst(N, current, goal);

    if (cnt1 == -1 && cnt2 == -1)
    {
        cnt = -1;
    }
    else if (cnt1 != -1 && cnt2 != -1)
    {
        cnt = min(cnt1, cnt2);
    }
    else
    {
        cnt = max(cnt1, cnt2);
    }

    cout << cnt << endl;

    return 0;
}