#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string change(int n, int k)
{
    string result = "";
    stack<int> temp;
    while (n > 0)
    {
        temp.push(n % k);
        n /= k;
    }

    while (!temp.empty())
    {
        result += temp.top() + '0';
        temp.pop();
    }

    return result;
}

bool isPrime(long long num)
{
    if (num == 1)
    {
        return false;
    }
    for (long long i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k)
{
    int answer = -1;

    string num = change(n, k);

    if (num.find('0') == string::npos)
    {
        if (isPrime(stoll(num)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int start_idx = 0;
    int cnt = 0;
    for (int i = 0; i <= num.length(); i++)
    {
        if (num[i] == '0' || num[i] == '\0')
        {
            if (start_idx != i)
            {
                string sub_num = num.substr(start_idx, i - start_idx);
                if (isPrime(stoll(sub_num)))
                {
                    cnt++;
                }
            }

            start_idx = i + 1;
        }
    }

    answer = cnt;
    return answer;
}