#include <iostream>
#include <string>

using namespace std;

string str;
int open[100000+10];
int close[100000+10];

void InputData(){
    cin >> str;
}

int main(){
    int ans = 0;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            open[i]++;
        }
        else
        {
            close[i]++;
        }
    }
    
    int openTotal = 0;
    int closeTotal = 0;
    for (int i = 0; i < len; i++)
    {
        openTotal += open[i];
        closeTotal += close[i];

        if (openTotal < closeTotal)
        {
            ans++;
            openTotal++;
            closeTotal--;
        }
        else if (i == len - 1 && openTotal != closeTotal)
        {
            ans += (openTotal - closeTotal) / 2;
        }
    }

    cout << ans << endl;// 출력하는 부분
    return 0;
}