#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        int idx = input.length() / 2;
        if (input[idx - 1] == input[idx])
        {
            cout << "Do-it" << endl;
        }
        else
        {
            cout << "Do-it-Not" << endl;
        }
    }
    return 0;
}