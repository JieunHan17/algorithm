#include <iostream>

using namespace std;

int W;//사용할 금액
int A[6];//각 동전 개수(갖고 있는)
int sol[6];//답
int coins[6] = {500, 100, 50, 10, 5, 1};

void InputData(){
	cin >> W;
	for (int i=0; i<6; i++){
		cin >> A[i];
	}
}

void OutputData(int ans){
	cout << ans << "\n";
	for (int i=0; i<6; i++){
		cout << sol[i] << " ";
	}
	cout << "\n";
}

int Solution()
{
    int cnt = 0;
    int total = 0;
    for (int i = 0; i < 6; i++)
    {
        total += A[i] * coins[i];
    }
    total -= W;
    for (int i = 0; i < 6; i++)
    {
        int temp = total / coins[i];
        if (temp > A[i])
        {
            temp = A[i];
        }
        total -= coins[i] * temp;
        cnt += (A[i] - temp);
        sol[i] = (A[i] - temp);
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int ans = -1;

	InputData();//입력받는 부분

	//여기서부터 작성
    ans = Solution();

	OutputData(ans);//출력하는 부분
	return 0;
}