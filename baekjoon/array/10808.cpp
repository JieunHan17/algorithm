#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    cin >> word;

    int alphabet[26] = {
        0,
    };

    for (int i = 0; i < word.length(); i++)
    {
        alphabet[word[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << ' ';
    }

    return 0;
}
