#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string words;
    int M;

    cin >> words;
    cin >> M;

    list<char> L;
    for (int i = 0; i < words.length(); i++)
    {
        L.push_back(words[i]);
    }

    list<char>::iterator cursor = L.end();

    for (int i = 0; i < M; i++)
    {
        char op;
        cin >> op;

        if (op == 'P')
        {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (op == 'L')
        {
            if (cursor != L.begin())
            {
                cursor--;
            }
        }
        else if (op == 'D')
        {
            if (cursor != L.end())
            {
                cursor++;
            }
        }
        else
        {
            if (cursor != L.begin())
            {
                cursor = L.erase(--cursor);
            }
        }
    }
    for (list<char>::iterator i = L.begin(); i != L.end(); i++)
    {
        cout << *i;
    }
}