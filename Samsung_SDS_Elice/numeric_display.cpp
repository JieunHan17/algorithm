#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

string A, B, filter;
int L;

int oper(int my_operand, char my_operator)
{
    int result;

    if (my_operator == '0')
    {
        result = my_operand;
    }
    else if (my_operator == '+')
    {
        // my_operand가 9인 경우 고려 필요
        if (my_operand == '9')
        {
            result = -1;
        }
        else
        {
            result = my_operand + 1;
        }
    }
    else if (my_operator == '-')
    {
        // my_operand가 0인 경우 고려 필요
        if (my_operand == '0')
        {
            result = -1;
        }
        else
        {
            result = my_operand - 1;
        }
    }

    cout << result << endl;
    return result;
}

int bfs()
{
    queue<pair<string, int> > q;
    q.push(make_pair(A, 0));

    bool isTargetBigger = A < B;

    while (!q.empty())
    {
        string num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (num == B)
        {
            return cnt;
        }

        for (int i = 0; i < 6; i++)
        {
            if ((L + i) > 6)
            {
                break;
            }

            // 필터 순서대로
            string num_copy_order = num;
            bool flag_order = true;
            for (int j = i; j < (i + L); j++)
            {
                int result = oper(num[j], filter[j]);

                if (result == -1)
                {
                    flag_order = false;
                    break;
                }
                else
                {
                    num_copy_order[j] = result;
                    cout << num_copy_order << endl;
                }
            }
            if ((flag_order && isTargetBigger && (num <= num_copy_order)) || (flag_order && !isTargetBigger && (num >= num_copy_order)))
            {
                q.push(make_pair(num_copy_order, cnt + 1));
            }

            // 필터 역순으로
            string num_copy_opposite = num;
            bool flag_opposite = true;
            for (int j = i; j < (i + L); j++)
            {
                int result = oper(num[j], filter[L - 1 - j]);

                if (result == -1)
                {
                    flag_opposite = false;
                    break;
                }
                else
                {
                    num_copy_opposite[j] = result;
                }
            }
            if ((flag_opposite && isTargetBigger && (num <= num_copy_opposite && num_copy_opposite <= B)) || (flag_opposite && !isTargetBigger && (num_copy_opposite <= num && num <= B)))
            {
                q.push(make_pair(num_copy_opposite, cnt + 1));
            }
        }
    }

    return -1;
}

int main()
{
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B >> L;
        cin >> filter;

        int length_of_A = A.length();
        int length_of_B = B.length();

        for (int j = 0; j < (6 - length_of_A); j++)
        {
            A.insert(0, 1, '0');
        }

        for (int j = 0; j < (6 - length_of_B); j++)
        {
            B.insert(0, 1, '0');
        }

        bfs();
        // cout << "#" << i + 1 << " " << bfs() << endl;
    }

    return 0;
}