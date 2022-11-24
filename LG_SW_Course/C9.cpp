#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N (100000)

int N, M;
int need[MAX_N];

void Input_Data(void) {
	cin >> N >> M;
	for (int i = 0; i < N;i++) {
		cin >> need[i];
	}
}

bool Check(int K)
{
    int cnt = 1;
    int budget = K;
    for (int i = 0; i < N; i++)
    {
        if (cnt > M)
        {
            return false;
        }

        if (need[i] <= budget)
        {
            budget -= need[i];
            continue;
        }
        else
        {
            cnt++;
            budget = K;
            i--;
        }
    }

    return cnt;
}

int BS(int low, int high)
{
	if (low > high)
		return low;

	int mid = (low + high) / 2;
	if (Check(mid))
		return BS(low, mid - 1);
	else
		return BS(mid + 1, high);
}

int main(void) {
	ios_base::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	int sol = -1;

	// 입력 받는 부분
	Input_Data();

	// 여기서부터 작성
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += need[i];
    }
    sol = BS(*max_element(need, need + N), sum);

	// 출력하는 부분
	cout << sol << '\n';

	return 0;
}