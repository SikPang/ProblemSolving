#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	return a[1] < b[1];
}

int solution(vector<vector<int>> targets)
{
	int answer = 1;

	sort(targets.begin(), targets.end(), cmp);
	int end = targets[0][1];
	for (int i=1; i<targets.size(); ++i)
	{
		if (end <= targets[i][0])
		{
			++answer;
			end = targets[i][1];
		}
	}
	return answer;
}