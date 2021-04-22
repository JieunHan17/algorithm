#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands)
{
    vector<int> answer;
    int input_i, input_j, input_k;
    int length;

    for (int i = 0; i < commands.size(); i++)
    {
        input_i = commands[i][0];
        input_j = commands[i][1];
        input_k = commands[i][2];
        length = input_j - input_i + 1;

        int new_array[100] = {
            0,
        };

        for (int idx = input_i - 1; idx <= input_j - 1; idx++)
        {
            new_array[idx - (input_i - 1)] = array[idx];
        }

        sort(new_array, new_array + length);

        answer.push_back(new_array[input_k - 1]);
    }

    return answer;
}
