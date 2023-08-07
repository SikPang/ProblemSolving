#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
	answer[0] = 0;
	answer[1] = 1000000;
	int sum = 0;
	int startIdx = 0;
	
	for (int i = 0; i < sequence.size(); ++i)
	{
		sum += sequence[i];

		while (startIdx <= i && sum >= k)
		{
			if (sum == k && answer[1] - answer[0] > i - startIdx)
			{
				answer[0] = startIdx;
				answer[1] = i;
				break;
			}
			sum -= sequence[startIdx];
			++startIdx;
		}
	}

    return answer;
}