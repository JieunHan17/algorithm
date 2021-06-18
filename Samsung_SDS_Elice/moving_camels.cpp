#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int depart[8];
int dest[8];
int totalTime = 0;

void cal(int N)
{
    int departNum = N;
    int destNum = 0;
    bool isDestination = false;

    while (departNum > 0)
    {
        sort(depart, depart + 8);
        sort(dest, dest + 8);

        cout << "~~~~~~~" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << depart[i] << endl;
        }
        cout << "~~~~~~~" << endl;

        if (isDestination == false)
        {
            if (departNum == 1 || departNum == 2)
            {
                totalTime += depart[departNum - 1];

                cout << "-------" << endl;
                for (int i = 0; i < 8; i++)
                {
                    cout << depart[i] << endl;
                }
                cout << "-------" << endl;

                cout << "first" << endl;
                cout << "totalTime: " << totalTime << endl;

                return;
            }
            else if (N == departNum)
            {
                // 제일 작은 거 2개 선택
                totalTime += depart[1];
                dest[destNum] = depart[0];
                dest[destNum + 1] = depart[1];
                depart[0] = 1001;
                depart[1] = 1001;
                departNum -= 2;
                destNum += 2;
                isDestination = true;

                cout << "-------" << endl;
                for (int i = 0; i < 8; i++)
                {
                    cout << depart[i] << endl;
                }
                cout << "-------" << endl;

                cout << "second" << endl;
                cout << "totalTime: " << totalTime << endl;
            }
            else
            {
                // 제일 큰 거 2개 선택
                totalTime += depart[departNum - 1];
                dest[destNum] = depart[departNum - 1];
                dest[destNum + 1] = depart[departNum - 2];
                depart[departNum - 1] = 1001;
                depart[departNum - 2] = 1001;
                departNum -= 2;
                destNum += 2;
                isDestination = true;

                cout << "-------" << endl;
                for (int i = 0; i < 8; i++)
                {
                    cout << depart[i] << endl;
                }
                cout << "-------" << endl;

                cout << "third" << endl;
                cout << "totalTime: " << totalTime << endl;
            }
        }
        else
        {
            totalTime += dest[0];
            depart[departNum] = dest[0];
            dest[0] = 1001;
            departNum += 1;
            destNum -= 1;
            isDestination = false;

            cout << "-------" << endl;
            for (int i = 0; i < 8; i++)
            {
                cout << depart[i] << endl;
            }
            cout << "-------" << endl;

            cout << "fourth" << endl;
            cout << "totalTime: " << totalTime << endl;
        }
    }

    return;
}

int main()
{
    fill(depart, depart + 8, 1001);
    fill(dest, dest + 8, 1001);

    int T, N;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &depart[j]);
        }
        sort(depart, depart + 8);

        cal(N);
        cout << "#" << i + 1 << " " << totalTime << endl;

        fill(depart, depart + 8, 1001);
        fill(dest, dest + 8, 1001);
        totalTime = 0;
    }
    return 0;
}