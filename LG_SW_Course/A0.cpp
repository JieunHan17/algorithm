#include <iostream>
 
using namespace std;
 
#define MAXN (100)
 
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부
 
void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}
 
int main(){
    int ans = -1;
    InputData();//입력받는 부분
 
    //여기서부터 작성
    int time_cnt = 0;
    for (int i = 0; i < N; i++)
    {
        time_cnt += T[i];
        if (time_cnt >= 210)
        {
            if (K == 0)
            {
                K = 8;
            }
            ans = K;
            break;
        }
         
        if (Z[i] == 'T')
        {
            K = (K + 1) % 8;
        }
    }
 
    cout << ans << endl;//출력하는 부분
    return 0;
}