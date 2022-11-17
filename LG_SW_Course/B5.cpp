#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N;
int ID[500+10];
int S[500+10];
int E[500+10];
int sol[500+10];
vector<pair<int, pair<int, int> > > v;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> ID[i] >> S[i] >> E[i];
        v.push_back(make_pair(ID[i], make_pair(S[i], E[i])));
    }
}

bool compare(pair<int, pair<int, int>> meeting1, pair<int, pair<int, int>> meeting2)
{
    if (meeting1.second.second == meeting2.second.second)
    {
        return meeting1.second.first < meeting2.second.first;
    }
    return meeting1.second.second < meeting2.second.second;
}

void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

int main(){
    int ans = 0;

    InputData();// 입력받는 부분

    //여기서부터 작성
    sort(v.begin(), v.end(), compare);
    
    int endTime = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i].second.first >= endTime)
        {
            sol[ans] = v[i].first;
            ans++;
            endTime = v[i].second.second;
        }
    }
    
    OutputData(ans);// 출력하는 부분
    return 0;
}