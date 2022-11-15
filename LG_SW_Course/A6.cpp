#include <iostream>
 
using namespace std;
 
int N;//빌딩의 층수
int array[10] = {0, 1, 2, 3, 0, 4, 5, 6, 7, 8};
 
void InputData(){
    cin >> N;
}
 
int main(){
    int ans = -1;
    InputData();//입력받는 부분
 
    //여기서부터 작성
    int real = 0;
    int digit = 1;
    while (N)
    {
        real += array[N % 10] * digit;
        N /= 10;
        digit *= 9;
    }
     
    ans = real;
    cout << ans << endl;//출력하는 부분
    return 0;
}