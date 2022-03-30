#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> input;
vector<int> arr;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        input.push_back(num);
    }
    sort(input.begin(), input.end());
    
    for (int i = 0; i < M; i++)
    {
        arr.push_back(0);
    }
    for (int i = M; i < N; i++)
    {
        arr.push_back(1);
    }

    do
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == 0)
            {
                printf("%d ", input[i]);
            }
        }
        printf("\n");
    } while (next_permutation(arr.begin(), arr.end()));

    return 0;
}