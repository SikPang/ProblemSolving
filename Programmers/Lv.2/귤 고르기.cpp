#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}

int solution(int k, vector<int> tan)
{
    int answer = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < tan.size(); ++i)
    {
        if (map.find(tan[i]) != map.end())
            ++map[tan[i]];
        else
            map.insert(make_pair(tan[i], 1));
    }

    vector< pair<int, int> > vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), cmp);

    int num = 0;
    int prev = 0;
    for (int i = vec.size() - 1; i >= 0; --i)
    {
        if (num >= k) break;

        ++answer;
        num += vec[i].second;

        if (prev != vec[i].second)
            prev = vec[i].second;
    }

    return answer;
}