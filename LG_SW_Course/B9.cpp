#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <unordered_map>
 
using namespace std;
 
#define MAXN ((int)5e4)
#define INF 9876543210
 
int N;
vector<pair<int, int> > v;
set<int> cows;
 
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        int x, id;
        cin >> x >> id;
        v.push_back(make_pair(x, id));
        cows.insert(id);
    }
}
 
bool compare(pair<int, int> cow1, pair<int, int> cow2)
{
    return cow1.first < cow2.first;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     
    int ans = INF;
 
    InputData();
 
    sort(v.begin(), v.end(), compare);
     
    int totalCowTypeNums = cows.size();
     
    int start = 0;
    int end = start;
     
    unordered_map<int, int> cowsTemp;
    cowsTemp.insert(make_pair(v[start].second, 1));
     
    while (1)
    {
        if (cowsTemp.size() == totalCowTypeNums)
        {
            ans = min(ans, v[end].first - v[start].first);
            if (cowsTemp[v[start].second] == 1)
            {
                cowsTemp.erase(v[start].second);
            }
            else
            {
                cowsTemp[v[start].second]--;
            }
            start++;
        }
        else if (cowsTemp.size() > totalCowTypeNums)
        {
            if (cowsTemp[v[start].second] == 1)
            {
                cowsTemp.erase(v[start].second);
            }
            else
            {
                cowsTemp[v[start].second]--;
            }
            start++;
        }
        else if (cowsTemp.size() < totalCowTypeNums)
        {
            end++;
            if (end == N)
            {
                break;
            }
            if (cowsTemp.find(v[end].second) == cowsTemp.end())
            {
                cowsTemp.insert(make_pair(v[end].second, 1));
            }
            else
            {
                cowsTemp[v[end].second]++;
            }
        }
    }
     
    cout << ans << "\n";
 
    return 0;
}