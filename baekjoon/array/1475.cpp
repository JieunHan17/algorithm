#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string roomNum;
    cin >> roomNum;

    int freq[10] = {
        0,
    };

    for (int i = 0; i < roomNum.length(); i++)
    {
        freq[roomNum[i] - '0']++;
    }

    int sixAndNine = freq[6] + freq[9];
    int pair = max(freq[6], freq[9]);
    if (sixAndNine >= 2)
    {
        pair = ceil(sixAndNine / 2.0);
    }

    int maximum = pair;
    for (int i = 0; i < 10; i++)
    {

        if (i != 6 && i != 9 && freq[i] > maximum)
        {
            maximum = freq[i];
        }
    }

    cout << maximum;
    return 0;
}