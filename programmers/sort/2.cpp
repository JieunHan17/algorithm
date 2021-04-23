#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int x, const int y)
{
    if (x == y)
    {
        return false;
    }

    else
    {
        string case_1;
        string case_2;

        case_1 = to_string(x) + to_string(y);
        case_2 = to_string(y) + to_string(x);

        if (case_1.compare(case_2) > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < numbers.size(); i++)
    {
        if (answer == "0" && numbers[i] == 0)
        {
            answer = "0";
        }
        else
        {
            answer += to_string(numbers[i]);
        }
    }
    return answer;
}