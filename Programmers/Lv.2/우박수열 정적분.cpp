#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer(ranges.size());
    vector<double> area;
    int prevK;
    
    while (k > 1)
    {
		prevK = k;
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
        
        // 사다리꼴 넓이 = ((윗변 + 아랫변) * 높이) / 2
        double curArea = (prevK + k) / 2.0;
        area.push_back(curArea);
    }
    area.push_back(0);
    
    for (int i=0; i<ranges.size(); ++i)
    {
        int end = area.size() + ranges[i][1] - 1;
        if (end < ranges[i][0])
        {
            answer[i] = -1;
            continue;
        }
        
        double sum = 0;
        for (int j=ranges[i][0]; j<end; ++j)
            sum += area[j];
        answer[i] = sum;
    }
    return answer;
}