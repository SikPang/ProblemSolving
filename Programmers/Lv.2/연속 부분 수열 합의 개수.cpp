#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) 
{
	unordered_set<int> set;

	// 선택할 개수
	for (int i = 1; i <= elements.size(); ++i)
	{
		int sum = 0;
		int head = 0;
		int tail = i - 1;

		// 0부터 선택할 개수 더하기
		for (int k = 0; k < i; ++k)
			sum += elements[k % elements.size()];

		// 더한 개수를 보존하면서 head 원소를 빼고, tail + 1 원소를 추가하며 반복
		for (int j = 0; j < elements.size(); ++j)
		{
			if (set.find(sum) == set.end())
				set.insert(sum);

			sum -= elements[head % elements.size()];
			sum += elements[(tail + 1) % elements.size()];

			++head;
			++tail;
		}
	}
	return set.size();
}