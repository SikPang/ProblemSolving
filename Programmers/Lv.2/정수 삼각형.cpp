#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i=1; i<triangle.size(); ++i)
    {    
        for (int j=0; j<triangle[i].size(); ++j)
        {
            if (j == 0)
                triangle[i][j] += triangle[i-1][j];
            else if (j == triangle[i-1].size())
                triangle[i][j] += triangle[i-1][j-1];
            else
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }
    return *max_element(triangle.back().begin(), triangle.back().end());
}