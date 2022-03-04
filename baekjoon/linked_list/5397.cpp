#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    while (num--)
    {
        string input;
        cin >> input;

        list<char> L;
        list<char>::iterator cursor = L.begin();

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '<')
            {
                if (cursor != L.begin())
                {
                    cursor--;
                }
            }
            else if (input[i] == '>')
            {
                if (cursor != L.end())
                {
                    cursor++;
                }
            }
            else if (input[i] == '-')
            {
                if (cursor != L.begin())
                {
                    cursor = L.erase(--cursor);
                }
            }
            else
            {
                L.insert(cursor, input[i]);
            }
        }
        for (list<char>::iterator c = L.begin(); c != L.end(); c++)
        {
            cout << *c;
        }
        cout << '\n';
    }
}
