
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76
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