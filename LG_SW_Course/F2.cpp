#include <iostream>

using namespace std;

#define MAXM (7)

int N;//임의의수
int WV[2][MAXM+1];
int A;//하나당 추가 가치

int sol = -1;//가장 가치가 높은 수식의 수식 가치
int solcnt[MAXM+1];//사용횟수

int nums[7] = {1, 2, 4, 8, 16, 32, 64};
int used[7];

void InputData(){
	cin >> N;
	for (int i=0; i<2; i++){
		for (int j=0; j<MAXM; j++){
			cin >> WV[i][j];
		}
	}
	cin >> A;
}

void OutputData(){
	cout << sol << "\n";
	for (int i=0; i<MAXM; i++){
		cout << solcnt[i] << " ";
	}
	cout << "\n";
}

void DFS(int start, int total)
{
    if (total > N)
    {
        return;
    }
	if (total == N)
	{
		int value = 0;
		for (int i = 0; i < 7; i++)
		{
			if (used[i] >= 5)
			{
				value += (WV[1][i] * used[i] + A * used[i]);
			}
			else
			{
				value += (WV[0][i] * used[i] + A * used[i]);
			}
		}

		if (value > sol)
		{
			sol = value;
			for (int i = 0; i < 7; i++)
			{
				solcnt[i] = used[i];
			}
		}

		return;
	}

	for (int i = start; i < 7; i++)
	{
		used[i]++;
		DFS(i, total + nums[i]);
		used[i]--;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력

	//여기서부터 작성
    DFS(0, 0);

	OutputData();//출력
	return 0;
}