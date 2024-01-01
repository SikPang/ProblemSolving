#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int target = 0;
int sortby = 0;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[sortby] < b[sortby];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    const string kind[4] = {"code", "date", "maximum", "remain"};
    
    for (int i=0; i<4; ++i)
    {
        if (ext == kind[i])
            target = i; 
        if (sort_by == kind[i])
            sortby = i;
    }
    
    for (int i=0; i<data.size(); ++i)
    {
        if (data[i][target] < val_ext)
            answer.push_back(data[i]);
    }
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}
