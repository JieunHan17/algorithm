#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAXN ((int)1e5)

int N;//영화수
vector<pair<int, int> > v;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        int s, e;
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }
}

bool compare(pair<int, int> movie1, pair<int, int> movie2)
{
    if (movie1.second == movie2.second)
    {
        return movie1.first < movie2.first;
    }
    return movie1.second < movie2.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int ans = 0;
	InputData();//입력받는 부분

	//여기서부터 작성
    sort(v.begin(), v.end(), compare);
    
    int endTime = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i].second - v[i].first < 2)
        {
            continue;
        }
        if (v[i].first >= endTime)
        {
            ans++;
            endTime = v[i].second;
        }
    }
	cout << ans << "\n";//출력하는 부분
	return 0;
} 