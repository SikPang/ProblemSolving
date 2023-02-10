#include <deque>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
	vector<int> answer;
	deque< pair<int, int> > deq;
	unordered_map<int, int> map;

	for (int i = 0; i < numbers.size(); ++i)
	{
		while (!deq.empty() && deq.back().first < numbers[i])
		{
			map.insert(make_pair(deq.back().second, numbers[i]));
			deq.pop_back();
		}
		deq.push_back(make_pair(numbers[i], i));
	}

	for (int i = 0; i < numbers.size(); ++i)
	{
		if (map.find(i) == map.end())
		{
			answer.push_back(-1);
			deq.pop_front();
		}
		else
			answer.push_back(map[i]);
	}

	return answer;
}