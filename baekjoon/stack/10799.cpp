#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    stack<char> s;
    int numOfSticks = 0;
    int numOfPieces = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            numOfSticks++;
        }
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                numOfSticks--;
                numOfPieces += numOfSticks;
            }
            else
            {
                numOfSticks--;
                numOfPieces++;
            }
        }
        s.push(str[i]);
    }

    cout << numOfPieces;

    return 0;
}