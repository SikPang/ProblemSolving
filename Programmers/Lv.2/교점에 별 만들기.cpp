#include <math.h>
#include <string>
#include <vector>
#include <climits>
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y)

using namespace std;

vector<string> solution(vector<vector<int>> line) {
	vector<pair<double,double>> dup;
	long long left = LLONG_MAX, right = LLONG_MIN, top = LLONG_MAX, bottom = LLONG_MIN;
	
	for (int i=0; i<line.size(); ++i)
	{
		for (int j=i+1; j<line.size(); ++j)
		{
			double denom = (double)line[i][0] * line[j][1] - (double)line[j][0] * line[i][1];

			if (denom == 0)
				continue;
			
			double x = ((double)line[i][1] * line[j][2] - (double)line[j][1] * line[i][2]) / denom;
			double y = ((double)line[i][2] * line[j][0] - (double)line[i][0] * line[j][2]) / denom;

			if (x - (long long)x != 0 || y - (long long)y != 0)
				continue;
			
			dup.push_back(make_pair(x, -y));
			left = min(left, x);
			right = max(right, x);
			top = min(top, -y);
			bottom = max(bottom, -y);
		}
	}
	
	vector<string> answer(abs(bottom-top)+1, string(abs(right-left)+1, '.'));
	for (auto iter=dup.begin(); iter != dup.end(); ++iter)
		answer[iter->second - top][iter->first - left] = '*';
    return answer;
}