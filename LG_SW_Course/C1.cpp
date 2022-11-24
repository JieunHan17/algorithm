#include <iostream>
#include <string>

using namespace std;

string str;

void InputData(){
    cin >> str;
}

int Solution()
{
    int depth = 0;
    int open = 0, close = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            depth++;
            open++;
        }
        else
        {
            depth--;
            close++;
        }
        if (depth == 1)
        {
            open = 0;
        }
        if (depth < 0)
        {
            return close;
        }
    }
    return open;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solution();

    cout << ans << endl;// 출력하는 부분
    return 0;
}