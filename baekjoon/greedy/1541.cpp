#include <string>
#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int result = 0;
    int startIdx = 0;
    bool flag = false;
    for (int i = 0; i <= input.length(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '\0')
        {
            int num = stoi(input.substr(startIdx, i - startIdx));
            if (flag)
            {
                result -= num;
            }
            else
            {
                result += num;
            }

            if (input[i] == '-')
            {
                flag = true;
            }

            startIdx = i + 1;
        }
    }

    cout << result << endl;

    return 0;
}