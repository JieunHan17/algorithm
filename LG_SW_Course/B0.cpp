#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
char S[10000+10][20+10];
unordered_map<string, int> um;
vector<int> ANS[10000+10];

void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> S[i];
    }
}

int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    int idx = -1;
    for (int i = 1; i <= N; i++)
    {
        auto iter = um.find(S[i]);
        if (iter == um.end())
        {
            um[S[i]]= ++idx;
            ANS[idx].push_back(i);
        }
        else
        {
            ANS[iter->second].push_back(i);
        }
    }
    
    if (um.size() == N)
    {
        cout << "unique\n";
        return 0;
    }
    
    for (int i = 0; i < um.size(); i++)
    {
        if (ANS[i].size() == 1)
        {
            continue;
        }
        cout << S[ANS[i][0]] << " ";
        for (int j = 0; j < ANS[i].size(); j++)
        {
            cout << ANS[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}