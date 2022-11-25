#include <iostream>
#include <queue>

using namespace std;

int S, E;//출발 정류장 번호, 도착 정류장 번호
int primeNums[10000];
bool visited[10000];

void InputData(){
    cin >> S >> E;
}

void GetPrimeNums()
{
    for (int i = 2; i <= 9999; i++)
    {
        primeNums[i] = 1;
    }

    for (int i = 2; i * i <= 9999; i++)
    {
        if (primeNums[i])
        {
            for (int j = i * i; j <= 9999; j += i)
            {
                primeNums[j] = 0;
            }
        }
    }
}

bool Check(int num, int target)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (num % 10 != target % 10)
        {
            cnt++;
        }
        num /= 10;
        target /= 10;
    }

    if (cnt > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int BFS()
{   
    queue<pair<int, int> > q;
    q.push(make_pair(0, S));
    visited[S] = true;
    while (!q.empty())
    {
        int curCnt = q.front().first;
        int curNum = q.front().second;
        q.pop();

        for (int i = 1000; i < 10000; i++)
        {
            if (visited[i])
            {
                continue;
            }
            if (!Check(curNum, i))
            {
                continue;
            }

            if (i == E)
            {
                return curCnt + 1;
            }

            if (primeNums[i])
            {
                q.push(make_pair(curCnt + 1, i));
                visited[i] = true;
            }
        }
    }
    return -1;
}

int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    GetPrimeNums();
    ans = BFS();

    cout << ans << endl;// 출력하는 부분
    return 0;
}