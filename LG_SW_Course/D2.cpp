#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
 
using namespace std;
 
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
long long A[MAXNM+10];//잔디 구간 시작
long long B[MAXNM+10];//잔디 구간 끝
vector<pair<long long, long long> > v;
 
void InputData(){
    cin >> N >> M;
    for (int i=0 ; i<M ; i++){
        cin >> A[i] >> B[i];
        v.push_back(make_pair(A[i], B[i]));
    }
}
 
bool compare(pair<long long, long long> grass1, pair<long long, long long> grass2)
{
    return grass1.first < grass2.first;
}
 
bool Check(long long D)
{
    int cnt = 1;
    int idx = 0;
    long long loc = v[idx].first;
    while (cnt <= N)
    {
        if (loc + D <= v[idx].second)
        {
            // 그 전에 idx의 second에 있다가 그 다음 idx로 넘어와서
            // second보다 작은 것만 비교하면 잔디 위가 아닐 수 있음
            if (loc + D >= v[idx].first)
            {
                loc += D;
            }
            else
            {
                loc = v[idx].first;
            }
            cnt++;
        }
        else
        {
            // 사실상 이미 위 if절에서 잔디 위에 있는 것을 다 판별해주므로
            // 여기서는 그 다음 잔디로 넘어가는 것만 해주면 됨
            if (idx + 1 == M)
            {
                break;
            }
            idx++;
        }
    }
 
    if (cnt < N)
    {
        return false;
    }
    else
    {
        return true;
    }
}
 
long long BS(long long low, long long high) // Upper Bound
{
    if (low > high)
    {
        return high;
    }
    long long mid = (low + high) / 2;
    if (Check(mid))
    {
        return BS(mid + 1, high);
    }
    else
    {
        return BS(low, mid - 1);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    long long ans = -1;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    sort(v.begin(), v.end(), compare);
    ans = BS(1, v[M - 1].second - v[0].first);
 
    cout << ans << "\n";// 출력하는 부분
    return 0;
}