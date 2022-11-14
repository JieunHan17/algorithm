#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define MAXN ((int)1e3)
 
int N;
int check[MAXN + 10];
 
void InputData(){
    cin >> N;
}
 
int Cal(int num)
{
    int total = 0;
    while (num > 0)
    {
        total += (num % 10) * (num % 10);
        num /= 10;
    }
    return total;
}
 
void Check(int num)
{
    vector<int> v;
    v.push_back(num);
     
    bool isHappy = false;
    while (1)
    {
        num = Cal(num);
        if (check[num] == 1)
        {
            isHappy = true;
            break;
        }
        else if (check[num] == -1)
        {
            break;
        }
         
        if (find(v.begin(), v.end(), num) != v.end())
        {
            break;
        }
        v.push_back(num);
    }
     
    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        if (isHappy)
        {
            check[*iter] = 1;
        }
        else
        {
            check[*iter] = -1;
        }
    }
     
    return;
}
 
int main(){
    int ans = -1;
    InputData();//입력받는 부분
 
    //여기서부터 작성
    check[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (check[i] == 0)
        {
            Check(i);
        }
    }
     
    for (int i = N; i > 0; i--)
    {
        if (check[i] == 1)
        {
            ans = i;
            break;
        }
    }
 
    cout << ans << endl;//출력하는 부분
    return 0;
}