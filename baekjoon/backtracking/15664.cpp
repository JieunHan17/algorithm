#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
vector<int> input;
vector<int> arr;
vector<vector<int> > output;

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
        vector<int> temp;
        for (int i = 0; i < N; i++)
        {
            if (!arr[i])
            {
                temp.push_back(input[i]);
            }
        }
        output.push_back(temp);
    } while (next_permutation(arr.begin(), arr.end()));

    sort(output.begin(), output.end());
    output.erase(unique(output.begin(), output.end()), output.end());
    
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}