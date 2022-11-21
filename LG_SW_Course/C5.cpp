#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define MAXN ((int)5e5)

int N, K;
char str[MAXN + 10];
stack<int> s;
int ans[MAXN + 10];

void InputData() {
	cin >> N >> K;
	cin >> str;
}

int main() {
	InputData();//입력 받는 부분

	//여기서부터 작성
	for (int i = 0; i < N; i++)
	{
	    while (!s.empty() && K && s.top() < str[i])
	    {
	        s.pop();
	        K--;
	    }
	    s.push(str[i]);
	}
	
	while (K-- > 0)
	{
	    s.pop();
	}
	
	int sz = s.size();
	str[sz] = 0;
	while (!s.empty())
	{
	    str[--sz] = s.top();
	    s.pop();
	   // ans[i] = s.top();
	   // s.pop();
	   // i++;
	}
	
	cout << str;
    
    // for (int i = 0; i < sz; i++)
    // {
    //     cout << ans[i];
    // }
	return 0;
}