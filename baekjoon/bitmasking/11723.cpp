#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int S = 0;

    for (int i = 0; i < M; i++)
    {
        string query;
        cin >> query;

        int num;
        if (query == "add")
        {
            cin >> num;
            S = S | (1 << (num - 1));
        }
        else if (query == "remove")
        {
            cin >> num;
            S = S & ~(1 << (num - 1));
        }
        else if (query == "check")
        {
            cin >> num;
            if (S & (1 << (num - 1)))
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (query == "toggle")
        {
            cin >> num;
            S = S ^ (1 << (num - 1));
        }
        else if (query == "all")
        {
            S = (1 << 21) - 1;
        }
        else
        {
            S = 0;
        }
    }
    return 0;
}