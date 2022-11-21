#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
string boom;

void InputData() {
	cin >> str;
	cin >> boom;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	InputData();
	
	int str_len = str.length();
	int boom_len = boom.length();
	int boom_idx = 0; // 그 다음 탐색할 폭발 문자열의 인덱스
	
	stack<pair<char, int> > s;
	
	for (int i = 0; i < str_len; i++)
    {
        if (str[i] == boom[boom_idx])
        {
            if (boom_idx == boom_len - 1)
            {
                for (int j = 0; j < boom_len - 1; j++)
                {
                    s.pop();
                }

                if (!s.empty())
                {
                    boom_idx = s.top().second;
                }
                else
                {
                    boom_idx = 0;
                }
            }
            else
            {
                boom_idx++;
                s.push(make_pair(str[i], boom_idx));
            }
        }
        else if (str[i] == boom[0] && boom_idx != 0)
        {
            boom_idx = 1;
            s.push(make_pair(str[i], boom_idx));
        }
        else
        {
            boom_idx = 0;
            s.push(make_pair(str[i], boom_idx));
        }
    }

    if (s.empty())
    {
        cout << "FRULA" << endl;
    }
    else
    {
        stack<char> reverse;

        while (!s.empty())
        {
            reverse.push(s.top().first);
            s.pop();
        }

        string answer = "";
        while (!reverse.empty())
        {
            answer += reverse.top();
            reverse.pop();
        }

        cout << answer << endl;
    }
	return 0;
}