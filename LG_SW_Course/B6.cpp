#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N;
int S[10000+10];
int E[10000+10];
int present;
int absent;

vector<pair<int, int> > v;

void InputData(void){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> S[i] >> E[i];
        v.push_back(make_pair(S[i], E[i]));
    }
}

bool compare(pair<int, int> student1, pair<int, int> student2)
{
    if (student1.first == student2.first)
    {
        return student1.second < student2.second;
    }
    return student1.first < student2.first;
}

int main(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    sort(v.begin(), v.end(), compare);
    
    int startTime = v[0].first;
    int endTime = v[0].second;
    present = endTime - startTime;
    for (int i = 1; i < N; i++)
    {
        if (v[i].first >= startTime && v[i].first <= endTime)
        {
            if (endTime < v[i].second)
            {
                endTime = v[i].second;
            }
        }
        else
        {
            absent = max(absent, v[i].first - endTime);
            startTime = v[i].first;
            endTime = v[i].second;
        }
        present = max(present, endTime - startTime);
    }

    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}