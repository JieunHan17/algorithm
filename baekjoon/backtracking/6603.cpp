#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 13

using namespace std;

int S[MAX];

int main()
{
    while (1)
    {
        int k;
        scanf("%d", &k);
        if (k == 0)
        {
            return 0;
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                scanf("%d", &S[i]);
            }

            vector<int> v;
            for (int i = 0; i < 6; i++)
            {
                v.push_back(0);
            }
            for (int i = 6; i < k; i++)
            {
                v.push_back(1);
            }

            do
            {
                for (int i = 0; i < k; i++)
                {
                    if (!v[i])
                    {
                        printf("%d ", S[i]);
                    }
                }
                printf("\n");
            } while (next_permutation(v.begin(), v.end()));
            
        }
        printf("\n");
    }
}