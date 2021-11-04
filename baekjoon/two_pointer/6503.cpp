#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            break;
        }

        cin.ignore();

        string sentence;
        getline(cin, sentence);

        int check[128] = {
            0,
        };
        int left = 0, right = 0;
        int duplicate = 0;
        int maximum = 0;

        check[sentence[0]] = 1;

        while (left <= right && right < sentence.length())
        {
            if (right - left + 1 - duplicate <= num)
            {
                maximum = max(maximum, right - left + 1);
                right++;

                if (check[sentence[right]] >= 1)
                {
                    duplicate++;
                }
                check[sentence[right]]++;
            }
            else
            {
                if (check[sentence[left]] >= 2)
                {
                    duplicate--;
                }
                check[sentence[left]]--;
                left++;
            }
        }

        cout << maximum << '\n';
    }

    return 0;
}