#include <algorithm>
#include <vector>

using namespace std;

int cool;

bool compare(const vector<int>& a, const vector<int>& b)
{
	if (a[cool] == b[cool])
		return a[0] > b[0];
	return a[cool] < b[cool];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    long long answer = -1;
	cool = col - 1;
	sort(data.begin(), data.end(), compare);

	for (int i = row_begin - 1; i < row_end; ++i)
	{
		long long curSum = 0;

		for (int j = 0; j < data[i].size(); ++j)
			curSum += data[i][j] % (i + 1);
		
		if (answer == -1)
			answer = curSum;
		else
			answer ^= curSum;
	}

    return answer;
}