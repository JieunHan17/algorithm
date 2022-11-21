#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int N;
string A;
vector<string> people[50+10];
stack<pair<int, char> > s;

void InputData(){
    cin >> N >> A;
}

int main (){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    int len = A.length();
    int numStart = 0;
    int depth;
    for (int i = 0; i < len; i++)
    {
        if (s.empty())
        {
            depth = 0;
        }
        else
        {
            depth = s.top().first;
        }
        
        if (A[i] >= '0' && A[i] <= '9')
        {
            continue;
        }
        
        if (A[i] == '<')
        {
            if (i - numStart != 0)
            {
                string num = A.substr(numStart, i - numStart);
                people[depth].push_back(num);
            }
            s.push(make_pair(depth + 1, A[i]));
        }
        else
        {
            s.pop();
        }
        
        numStart = i + 1;
    }
    
    for (int i = 0; i < people[N].size(); i++)
    {
        cout << people[N][i] << " ";
    }
    return 0;
}