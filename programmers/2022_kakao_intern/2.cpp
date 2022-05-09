#include <string>
#include <vector>
#include <algorithm>

#define MAX 600005

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = MAX;

    long long total = 0;
    vector<int> queue_total;
    for (int i = 0; i < queue1.size(); i++)
    {
        total += queue1[i];
        queue_total.push_back(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++)
    {
        total += queue2[i];
        queue_total.push_back(queue2[i]);
    }

    long long part_sum[MAX];
    fill(part_sum, part_sum + MAX, 0);
    part_sum[1] = queue_total[0];
    for (int i = 1; i < queue_total.size(); i++)
    {
        part_sum[i + 1] += part_sum[i] + queue_total[i];
    }

    int left = 0;
    int right = 0;
    while (left < queue_total.size())
    {
        long long temp;
        if (right < left)
        {
            temp = total - part_sum[left] + part_sum[right + 1];
        }
        else
        {
            temp = part_sum[right + 1] - part_sum[left];
        }

        if (temp == total / 2)
        {
            if (left < queue1.size() && right < queue1.size())
            {
                // left in queue1, right in queue1
                if (right == queue1.size() - 1)
                {
                    int result = left;
                    answer = min(answer, result);
                }
                else
                {
                    int result = (right + 1) + (left + queue2.size());
                    answer = min(answer, result);
                }
            }
            else if (left < queue1.size() && right >= queue1.size())
            {
                // left in queue1, right in queue2
                int result = left + (right - (queue1.size() - 1));
                answer = min(answer, result);
            }
            else if (left >= queue1.size() && right >= queue1.size())
            {
                // left in queue2, right in queue2
                if (right == queue_total.size() - 1)
                {
                    int result = left - queue1.size();
                    answer = min(answer, result);
                }
                else
                {
                    int result = (right - (queue1.size() - 1)) + left;
                    answer = min(answer, result);
                }
            }
            right++;
            if (right >= queue_total.size())
            {
                break;
            }
        }
        else if (temp < total / 2)
        {
            right++;
            if (right >= queue_total.size())
            {
                break;
            }
        }
        else if (temp > total / 2)
        {
            left++;
        }
    }
    
    if (answer == MAX)
    {
        answer = -1;
    }
    return answer;
}