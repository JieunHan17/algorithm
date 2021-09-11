#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <map>

using namespace std;

vector<string> splitReport(string s)
{
    vector<string> result;
    stringstream ss(s);
    string temp;
    while (ss >> temp)
    {
        result.push_back(temp);
    }
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;

    map<string, int> user_map;
    map<string, int> reported_num_map;
    map<string, bool> is_stopped_map;
    for (int i = 0; i < id_list.size(); i++)
    {
        user_map.insert(make_pair(id_list[i], i));
        reported_num_map.insert(make_pair(id_list[i], 0));
        is_stopped_map.insert(make_pair(id_list[i], false));
    }

    vector<string> reported_user[id_list.size()];
    for (int i = 0; i < report.size(); i++)
    {
        vector<string> query = splitReport(report[i]);
        bool flag = false;
        for (int j = 0; j < reported_user[user_map[query[0]]].size(); j++)
        {
            if (reported_user[user_map[query[0]]][j] == query[1])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            reported_num_map[query[1]]++;
            reported_user[user_map[query[0]]].push_back(query[1]);
        }
    }

    for (map<string, int>::iterator iter = reported_num_map.begin(); iter != reported_num_map.end(); iter++)
    {
        if (iter->second >= k)
        {
            if (!is_stopped_map[iter->first])
            {
                is_stopped_map[iter->first] = true;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < reported_user[i].size(); j++)
        {
            if (is_stopped_map[reported_user[i][j]])
            {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}