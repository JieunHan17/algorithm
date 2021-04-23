#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    int num[10001] = {
        0,
    };

    for (int i = 0; i < 10001; i++)
    {
        for (auto j = citations.begin(); j != citations.end(); ++j)
        {
            if (*j >= i)
            {
                num[i]++;
            }
        }
    }

    for (int i = 0; i < 10001; i++)
    {
        if (num[i] >= i)
        {
            answer = i;
        }
    }

    return answer;
}