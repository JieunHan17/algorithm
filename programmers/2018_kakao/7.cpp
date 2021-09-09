#include <string>
#include <stack>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;

    stack<int> s;
    int startIdx = 0;
    for (int i = 0; i < dartResult.length(); i++)
    {
        if (dartResult[i] == 'S')
        {
            int num = stoi(dartResult.substr(startIdx, i - startIdx));
            s.push(num);
            startIdx = i + 1;
        }
        else if (dartResult[i] == 'D')
        {
            int num = stoi(dartResult.substr(startIdx, i - startIdx));
            s.push(pow(num, 2));
            startIdx = i + 1;
        }
        else if (dartResult[i] == 'T')
        {
            int num = stoi(dartResult.substr(startIdx, i - startIdx));
            s.push(pow(num, 3));
            startIdx = i + 1;
        }
        else if (dartResult[i] == '*')
        {
            if (s.size() == 1)
            {
                int cur = s.top();
                s.pop();

                cur *= 2;
                s.push(cur);
            }
            else
            {
                int cur = s.top();
                s.pop();
                int prev = s.top();
                s.pop();

                prev *= 2;
                s.push(prev);

                cur *= 2;
                s.push(cur);
            }
            startIdx++;
        }
        else if (dartResult[i] == '#')
        {
            int cur = s.top();
            s.pop();

            cur *= (-1);
            s.push(cur);

            startIdx++;
        }
    }

    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    return answer;
}