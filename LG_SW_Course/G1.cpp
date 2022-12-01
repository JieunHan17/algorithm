#include <iostream>
#include <algorithm>

#define INF 987654321
#define MAX 1000

using namespace std;

int A, B, goalA, goalB;
int ans = INF;
bool used[MAX+10][MAX+10];

void InputData() {
	cin >> A >> B >> goalA >> goalB;
}

void DFS(int curA, int curB, int cnt)
{
    if (cnt > ans)
    {
        return; //가지치기
    }

    if (curA == goalA && curB == goalB)
    {
        ans = min(ans, cnt);
        return;
    }

    /* 첫 번째 작업 */
    if (curA != A)
    {
        if (!used[A][curB])
        {
            used[A][curB] = true;
            DFS(A, curB, cnt + 1); //F(A)
            used[A][curB] = false;
        }
    }
    if (curB != B)
    {
        if (!used[curA][B])
        {
            used[curA][B] = true;
            DFS(curA, B, cnt + 1); //F(B)
            used[curA][B] = false;
        }
    }

    /* 두 번째 작업 */
    if (curA != 0)
    {
        if (!used[0][curB])
        {
            used[0][curB] = true;
            DFS(0, curB, cnt + 1); //E(A)
            used[0][curB] = false;
        }
    }
    if (curB != 0)
    {
        if (!used[curA][0])
        {
            used[curA][0] = true;
            DFS(curA, 0, cnt + 1); //E(B)
            used[curA][0] = false;
        }
    }

    /* 세 번째 작업 */
    if (curB + curA <= B) //M(A, B)
    { 
        if (!used[0][curB + curA])
        {
            used[0][curB + curA] = true;
            DFS(0, curB + curA, cnt + 1);
            used[0][curB + curA] = false;
        }
    }
    else
    {
        if (!used[curA - (B - curB)][B])
        {
            used[curA - (B - curB)][B] = true;
            DFS(curA - (B - curB), B, cnt + 1);
            used[curA - (B - curB)][B] = false;
        }
    }

    if (curA + curB <= A) //M(B, A)
    {
        if (!used[curA + curB][0])
        {
            used[curA + curB][0] = true;
            DFS(curA + curB, 0, cnt + 1);
            used[curA + curB][0] = false;
        }
    }
    else
    {
        if (!used[A][curB - (A - curA)])
        {
            used[A][curB - (A - curA)] = true;
            DFS(A, curB - (A - curA), cnt + 1);
            used[A][curB - (A - curA)] = false;
        }
    }
}

int main() {
	InputData();//입력받는 부분
	
	// 여기서부터 작성
    used[0][0] = true;
    DFS(0, 0, 0);
    if (ans == INF)
    {
        ans = -1;
    }
	cout << ans << "\n";// 출력하는 부분
	return 0;
}