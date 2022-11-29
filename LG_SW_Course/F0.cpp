#include <iostream>
#include <algorithm>
 
using namespace std;
 
int N;
int W[21];
int ans = -1;
 
void InputData(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> W[i];
    }
}
 
bool Check(int num1, int num2)
{
    while (num1 != 0 || num2 != 0)
    {
        int rest1 = num1 % 10;
        int rest2 = num2 % 10;
        if (rest1 + rest2 >= 10)
        {
            return false;
        }
        num1 /= 10;
        num2 /= 10;
    }
    return true;
}
 
void DFS(int start, int cnt, int total)
{
    if (cnt == N)
    {
        return;
    }
 
    for (int i = start + 1; i <= N; i++)
    {
        if (Check(total, W[i]))
        {
            ans = max(ans, cnt + 1);
            DFS(i, cnt + 1, total + W[i]); // 태우는 경우
        }
    }
}
 
int main(){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    DFS(0, 0, 0);
 
    cout << ans << endl;//출력하는 부분
    return 0;
}