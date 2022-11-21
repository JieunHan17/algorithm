#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N;
int X[100+10];
int Y[100+10];
vector<pair<int, int> > v;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
        v.push_back(make_pair(X[i], Y[i]));
    }
}

bool compare(pair<int, int> temp1, pair<int, int> temp2)
{
    return temp1.first < temp2.first;
}

int main(){
    int ans = 1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    sort(v.begin(), v.end(), compare);
    
    int minTemp = v[0].first;
    int maxTemp = v[0].second;
    for (int i = 1; i < N; i++)
    {
        int curMinTemp = v[i].first;
        int curMaxTemp = v[i].second;
        if (curMinTemp >= minTemp && curMinTemp <= maxTemp)
        {
            minTemp = curMinTemp;
            maxTemp = min(maxTemp, curMaxTemp);
        }
        else
        {
            minTemp = curMinTemp;
            maxTemp = curMaxTemp;
            ans++;
        }
    }

    cout << ans << endl;// 출력하는 부분
    return 0;
}