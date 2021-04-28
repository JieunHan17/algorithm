#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int left, right;
    int x[10] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    int y[10] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += 'L';
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += 'R';
            right = numbers[i];
        }
        else
        {
            int diff_left = abs(x[left] - x[numbers[i]]) + abs(y[left] - y[numbers[i]]);
            int diff_right = abs(x[right] - x[numbers[i]]) + abs(y[right] - y[numbers[i]]);

            if (diff_left < diff_right)
            {
                answer += 'L';
                left = numbers[i];
            }
            else if (diff_right < diff_left)
            {
                answer += 'R';
                right = numbers[i];
            }
            else
            {
                if (hand == "right")
                {
                    answer += 'R';
                    right = numbers[i];
                }
                else
                {
                    answer += 'L';
                    left = numbers[i];
                }
            }
        }
    }
    return answer;
}