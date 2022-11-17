#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
 
using namespace std;
 
int N, C, M;
vector<pair<pair<int, int>, int> > v;
int status[2000+10];
 
void InputData(){
    cin >> N >> C;
    cin >> M;
    for (int i=0; i<M; i++){
        int s, e, num;
        cin >> s >> e >> num;
        v.push_back(make_pair(make_pair(s, e), num));
    }
}
 
bool compare(pair<pair<int, int>, int> info1, pair<pair<int, int>, int> info2)
{
    return info1.first.second < info2.first.second;
}
 
int main(){
    int ans = 0;
 
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    sort(v.begin(), v.end(), compare);
     
    for (int i = 0; i < M; i++)
    {
        int maxBox = 0;
        for (int j = v[i].first.first; j < v[i].first.second; j++)
        {
            if (maxBox < status[j])
            {
                maxBox = status[j];
            }
        }
         
        maxBox = C - maxBox;
        if (maxBox > v[i].second)
        {
            maxBox = v[i].second;
        }
         
        ans += maxBox;
         
        for (int j = v[i].first.first; j < v[i].first.second; j++)
        {
            status[j] += maxBox;
        }
    }
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}