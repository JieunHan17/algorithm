#include <cstdio>
#include <algorithm>

using namespace std;

int dice[10];
int red[22] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0}; // 도착 칸 인덱스: 21
int blue1[9] = {10, 13, 16, 19, 25, 30, 35, 40, 0}; // 도착 칸 인덱스: 8
int blue2[8] = {20, 22, 24, 25, 30, 35, 40, 0}; // 도착 칸 인덱스: 7
int blue3[9] = {30, 28, 27, 26, 25, 30, 35, 40, 0}; // 도착 칸 인덱스: 8

bool checkArrival(int loc[4], int check[4], int piece)
{
    if (check[piece] == 0)
    {
        if (loc[piece] >= 21)
        {
            return true;
        }
    }
    else if (check[piece] == 1)
    {
        if (loc[piece] - 5 >= 8)
        {
            return true;
        }
    }
    else if (check[piece] == 2)
    {
        if (loc[piece] - 10 >= 7)
        {
            return true;
        }
    }
    else if (check[piece] == 3)
    {
        if (loc[piece] - 15 >= 8)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &dice[i]);
    }

    int ans = 0;
    for (int temp = 0; temp < (1<<(2*10)); temp++)
    {
        int loc[4];
        fill(loc, loc + 4, 0);
        int check[4]; // 0: red 경로, 1: blue1 경로, 2: blue2 경로, 3: blue3 경로
        fill(check, check + 4, 0);
        int scores[4];
        fill(scores, scores + 4, 0);

        int brute = temp;
        int score = 0;
        bool stop = false;
        for (int i = 0; i < 10; i++)
        {
            int piece = brute % 4; // 0번 말부터 3번 말까지
            brute /= 4;

            /* 도착 칸에 있는 말이면 break & stop을 true로 */
            bool isArrived = checkArrival(loc, check, piece);
            if (isArrived)
            {
                stop = true;
                break;
            }
            
            /* 이동 */
            loc[piece] += dice[i];
            if (check[piece] == 0)
            {
                if (loc[piece] == 5)
                {
                    check[piece] = 1;
                }
                else if (loc[piece] == 10)
                {
                    check[piece] = 2;
                }
                else if (loc[piece] == 15)
                {
                    check[piece] = 3;
                }
            }

            /* 이동한 칸의 점수 저장 */
            if (checkArrival(loc, check, piece))
            {
                // 한번에 도착해버렸으면 점수 저장할 필요 없이 다음 말 이동
                scores[piece] = 0;
                continue;
            }
            else
            {
                if (check[piece] == 0)
                {
                    scores[piece] = red[loc[piece]];
                }
                else if (check[piece] == 1)
                {
                    scores[piece] = blue1[loc[piece] - 5];
                }
                else if (check[piece] == 2)
                {
                    scores[piece] = blue2[loc[piece] - 10];
                }
                else if (check[piece] == 3)
                {
                    scores[piece] = blue3[loc[piece] - 15];
                }
            }

            /* 25에 왔을 때 다 만나므로 별도 처리 */
            if (check[piece] == 1 && loc[piece] >= 9)
            {
                // blue1을 blue2 경로로 통일
                check[piece] = 2;
                loc[piece] = loc[piece] - 9 + 13;
            }
            else if (check[piece] == 3 && loc[piece] >= 19)
            {
                // blue3을 blue2 경로로 통일
                check[piece] = 2;
                loc[piece] = loc[piece] - 19 + 13;
            }

            /* 40에 왔을 때 다 만나므로 별도 처리 */
            if (scores[piece] == 40)
            {
                // blue를 red 경로로 통일
                check[piece] = 0;
                loc[piece] = 20;
            }

            /* 다른 말이 이미 있으면 break & stop을 true로 */
            for (int j = 0; j < 4; j++)
            {
                if (j != piece)
                {
                    if (scores[j] == scores[piece] && check[j] == check[piece])
                    {
                        stop = true;
                        break;
                    }
                }
            }
            if (stop)
            {
                break;
            }
            
            /* 점수 추가 */
            score += scores[piece];
        }

        if (!stop)
        {
            ans = max(ans, score);
        }
    }
    printf("%d", ans);
    return 0;
}

// 22, 24, 26, 28, 30 주의!