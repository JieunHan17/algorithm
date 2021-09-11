#include <string>
#include <vector>
#include <utility>
#include <map>
#include <iostream>

using namespace std;

vector<string> splitRecords(string s)
{
    vector<string> result;
    result.push_back(s.substr(0, 5));
    result.push_back(s.substr(6, 4));
    return result;
}

int timeToMin(string s)
{
    int result = 0;
    result += 60 * stoi(s.substr(0, 2));
    result += stoi(s.substr(3, 2));
    return result;
}

int calFee(int cumul_time, vector<int> fees)
{
    if (cumul_time <= fees[0])
    {
        return fees[1];
    }
    else
    {
        int fee = fees[1];
        int temp = (cumul_time - fees[0]) % fees[2];
        if (temp == 0)
        {
            fee += ((cumul_time - fees[0]) / fees[2]) * fees[3];
        }
        else
        {
            fee += ((cumul_time - fees[0]) / fees[2] + 1) * fees[3];
        }
        return fee;
    }
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    map<string, int> carIdx;
    int car_num = 0;
    for (int i = 0; i < records.size(); i++)
    {
        vector<string> record = splitRecords(records[i]);
        if (carIdx.find(record[1]) == carIdx.end())
        {
            carIdx.insert(make_pair(record[1], car_num));
            car_num++;
        }
    }

    vector<int> car[car_num];
    for (int i = 0; i < records.size(); i++)
    {
        vector<string> record = splitRecords(records[i]);
        car[carIdx[record[1]]].push_back(timeToMin(record[0]));
    }

    for (map<string, int>::iterator iter = carIdx.begin(); iter != carIdx.end(); iter++)
    {
        int idx = iter->second;
        int cumul_time = 0;
        for (int i = 0; i < car[idx].size(); i++)
        {
            cout << car[idx][i] << endl;
            if (i == car[idx].size() - 1)
            {
                cumul_time += (1439 - car[idx][i]);
            }
            else
            {
                cumul_time += (car[idx][i + 1] - car[idx][i]);
                i++;
            }
        }
        answer.push_back(calFee(cumul_time, fees));
    }

    return answer;
}