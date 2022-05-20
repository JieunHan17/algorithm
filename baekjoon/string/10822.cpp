#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    vector<string> numbers;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, ','))
    {
        numbers.push_back(temp);
    }

    long long result = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        result += stoll(numbers[i]);
    }

    cout << result;
    return 0;
}