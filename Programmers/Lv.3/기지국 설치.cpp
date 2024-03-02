#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int curStationIdx = 0;
    
    for (int cur=1; cur<=n; ++cur)
    {
        if (curStationIdx < stations.size() && cur >= stations[curStationIdx] - w)
        {
            cur = stations[curStationIdx] + w;
            ++curStationIdx;
        }
        else
        {
            cur += w * 2;
            ++answer;
        }
    }
    return answer;
}