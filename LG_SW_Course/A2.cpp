#include <iostream>
#include <unordered_map>
 
using namespace std;
 
int N, P;
unordered_map<int, int> m;
 
void InputData(){
    cin >> N >> P;
}
 
int main(){
    int ans = 0;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    int num = N;
    m.insert(make_pair(num, 1));
     
    while (1)
    {
        num = (num * N) % P;
        if (m.find(num) != m.end())
        {
            if (m[num] == 2)
            {
                break;
            }
            m[num]++;
            continue;
        }
        m.insert(make_pair(num, 1));
    }
     
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second == 2)
        {
            ans++;
        }
    }
     
    cout << ans << endl;// 출력하는 부분
    return 0;
}