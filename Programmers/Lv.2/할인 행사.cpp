#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
	unordered_map<string, int> want_map;
	unordered_map<string, int> cur_map;
	int map_size = 0;
	int answer = 0;

	for (int i = 0; i < want.size(); ++i)
		want_map.insert(make_pair(want[i], number[i]));

	for (int i = 0; i < discount.size(); ++i)
	{
		if (cur_map.find(discount[i]) == cur_map.end())
			cur_map.insert(make_pair(discount[i], 1));
		else
			++cur_map[discount[i]];

		++map_size;

		if (map_size > 10)
		{
			if (cur_map[discount[i - 10]] == 1)
				cur_map.erase(discount[i - 10]);
			else
				--cur_map[discount[i - 10]];

			--map_size;
		}

		bool check = true;
		for (int j = 0; j < want.size(); ++j)
		{
			if (cur_map.find(want[j]) == cur_map.end() || cur_map[want[j]] < want_map[want[j]])
			{
				check = false;
				break;
			}
		}
		if (check)
			++answer;
	}

	return answer;
}