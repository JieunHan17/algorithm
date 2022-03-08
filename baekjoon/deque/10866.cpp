#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> dq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string op;
        cin >> op;
        if (op == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (op == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (op == "pop_front")
        {
            if (dq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (op == "pop_back")
        {
            if (dq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (op == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (op == "empty")
        {
            if (dq.empty())
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (op == "front")
        {
            if (dq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << dq.front() << '\n';
            }
        }
        else if (op == "back")
        {
            if (dq.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << dq.back() << '\n';
            }
        }
    }
    return 0;
}