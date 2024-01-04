#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> buf;
    bool isChanged = false;
    
    for (int i=0; i<operations.size(); ++i)
    {
        if (operations[i].front() == 'I')
        {
            buf.push_back(stoi(operations[i].substr(2, operations[i].length()-2)));
            isChanged = true;
        }
        else if (operations[i].front() == 'D' && !buf.empty())
        {
            if (isChanged)
            {
                sort(buf.begin(), buf.end());
                isChanged = false;
            }
            
            if (operations[i][2] == '1')
                buf.pop_back();
            else
                buf.pop_front();
        }
    }
    if (isChanged)
        sort(buf.begin(), buf.end());
    int max = buf.empty() ? 0 : buf.back();
    int min = buf.empty() ? 0 : buf.front();
    return vector<int>{max, min};
}