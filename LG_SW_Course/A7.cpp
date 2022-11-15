#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MIN -1

using namespace std;

int N;
double D[10000+10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}

int main(){
    double ans = MIN;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    for (int start = 0; start < N; start++)
    {
        double sum = 1;
        for (int end = start; end < N; end++)
        {
            sum *= D[end];
            ans = max(ans, sum);
        }
    }

    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}