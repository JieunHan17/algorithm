#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN ((int)1e5)

int N;//개수
int F[MAXN + 10];

void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> F[i];
	}
}

bool Check(int targetIdx, int curIdx)
{
    if (F[targetIdx] >= F[curIdx] * 0.9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BS(int cur, int low, int high) // Lower Bound
{
    if (low > high)
    {
        return low;
    }
    int mid = (low + high) / 2;
    if (Check(mid, cur))
    {
        return BS(cur, low, mid - 1);
    }
    else
    {
        return BS(cur, mid + 1, high);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long ans = 0;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    sort(F, F + N);
    for (int i = N - 1; i >= 0 ; i--)
    {
        ans += (i - BS(i, 0, i));
    }

	cout << ans << "\n";// 출력하는 부분
	return 0;
}