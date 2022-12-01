#include <iostream>
#include <algorithm>

using namespace std;

#define MAXB (9)
#define MAXN ((int)1e5)

int B, N;
int S[MAXB + 10];
int P[MAXN + 10];
int passengerWeightSum[MAXN + 10];
bool used[MAXB + 10];
int sol;

void InputData()
{
    cin >> B >> N;
    for (int i = 1; i <= B; i++)
    {
        cin >> S[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }
}

int BS(int low, int high, int target) // Upper Bound
{
    if (low > high)
    {
        return high;
    }
    int mid = (low + high) / 2;
    if (passengerWeightSum[mid] <= target)
    {
        return BS(mid + 1, high, target);
    }
    else
    {
        return BS(low, mid - 1, target);
    }
}

void DFS(int passengerIdx, int unusedShipWeightSum)
{
    if (unusedShipWeightSum <= sol)
    {
        return; //가지치기
    }
    if (passengerIdx >= N)
    {
        sol = unusedShipWeightSum;
        return;
    }
    for (int i = 1; i <= B; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            int k = BS(0, N, passengerWeightSum[passengerIdx] + S[i]);
            DFS(k, unusedShipWeightSum - S[i]);
            used[i] = false;
        }
    }
}

int Solve()
{
    int shipWeightTotal = 0;
    for (int i = 1; i <= B; i++)
    {
        shipWeightTotal += S[i];
    }
    for (int i = 1; i <= N; i++)
    {
        passengerWeightSum[i] = passengerWeightSum[i - 1] + P[i];
    }
    sol = -1;
    DFS(0, shipWeightTotal);
    return sol;
}

int main(void)
{
    InputData(); //입력받는 부분

    //여기서부터 작성
    int ans = Solve();

    cout << ans << endl; //출력하는 부분
    return 0;
}