#include <iostream>

using namespace std;

int N, D, K, C;
int A[3000000+10];
int sushi[3000+10];

void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    int start = 0;
    int end;
    int cnt = 0;
    for (end = 0; end < start + K; end++)
    {
        if (sushi[A[end]] == 0)
        {
            cnt++;
        }
        sushi[A[end]]++;
    }
    if (sushi[C] == 0)
    {
        ans = max(ans, cnt + 1);
    }
    else
    {
        ans = max(ans, cnt);
    }
    
    while (start < N - 1)
    {
        if (sushi[A[start]] == 1)
        {
            cnt--;
        }
        sushi[A[start]]--;
        start++;
        
        if (sushi[A[end % N]] == 0)
        {
            cnt++;
        }
        sushi[A[end % N]]++;
        
        if (sushi[C] == 0)
        {
            ans = max(ans, cnt + 1);
        }
        else
        {
            ans = max(ans, cnt);
        }
        
        end++;
    }
    cout << ans << endl;// 출력하는 부분
    return 0;
}