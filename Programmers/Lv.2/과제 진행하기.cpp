#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool cmp(const vector<string>& a, const vector<string>& b)
{
    return a[1] < b[1];
}

int getGap(string& first, string& second)
{
    int firstMin = stoi(first.substr(3, 2));
    int firstHour = stoi(first.substr(0, 2));
    int secondMin = stoi(second.substr(3, 2));
    int secondHour = stoi(second.substr(0, 2));
    
    int minGap = secondMin - firstMin;
    int hourGap = secondHour - firstHour;
    if (minGap < 0)
    {
        hourGap -= 1;
        minGap = 60 + minGap;
    }
    return hourGap * 60 + minGap;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> stk;   // (name, remain)
    
    answer.reserve(plans.size());
    sort(plans.begin(), plans.end(), cmp);
    
    for (int i=1; i<plans.size(); ++i)
    {
        int gap = getGap(plans[i-1][1], plans[i][1]);
        int requireTime = stoi(plans[i-1][2]);
        
        if (requireTime > gap)
            stk.push(make_pair(plans[i-1][0], requireTime - gap));
        else
        {
            answer.push_back(plans[i-1][0]);
            if (requireTime < gap)
            {
                int remain = gap - requireTime;
                while (!stk.empty())
                {
                    pair<string, int> cur = stk.top();
                    stk.pop();
                    if (cur.second > remain)
                    {
                        cur.second -= remain;
                        stk.push(cur);
                        break;
                    }
                    else
					{
						answer.push_back(cur.first);
                        remain -= cur.second;
					}
                }
            }
        }
    }
    answer.push_back(plans.back()[0]);
    
    while (!stk.empty())
    {
        answer.push_back(stk.top().first);
        stk.pop();
    }
    
    return answer;
}