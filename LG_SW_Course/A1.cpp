#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAXN ((int)1e3)
 
int N;//정수개수
int A[MAXN + 10];//입력 정수
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}
 
bool isOver(int num)
{
    return num < 10 ? true : false;
}
 
int cal(int num)
{
    int total = 0;
    while (num > 0)
    {
        total += (num % 10);
        num /= 10;
    }
    return total;
}
 
int main(){
    int ans = -1;
    InputData();//입력 받는 부분
 
    //여기서부터 작성
    sort(A, A + N);
     
    int maxNum = -1;
    int maxValue = -1;
    for (int i = 0; i < N; i++)
    {
        int num = A[i];
        while (1)
        {
            if (isOver(num))
            {
                if (maxValue < num)
                {
                    maxNum = A[i];
                    maxValue = num;
                }
                break;
            }
            num = cal(num);
        }
    }
     
    ans = maxNum;
    cout << ans << endl;//출력하는 부분
    return 0;
}