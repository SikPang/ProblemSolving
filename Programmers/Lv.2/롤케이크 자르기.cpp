#include <vector>
#include <unordered_map>
using namespace std;

void pop_map(unordered_map<int, int>& map, int data)
{
	if (map[data] > 1)
		--map[data];
	else
		map.erase(data);
}

void push_map(unordered_map<int, int> &map, int data)
{
	if (map.find(data) == map.end())
		map.insert(make_pair(data, 1));
	else
		++map[data];
}

int solution(vector<int> topping) 
{
	int answer = 0;
	unordered_map<int, int> lmap;
	unordered_map<int, int> rmap;

	for (int i = 0; i < topping.size(); ++i)
		push_map(rmap, topping[i]);

	for (int i = 0; i < topping.size(); ++i)
	{
		push_map(lmap, topping[i]);
		pop_map(rmap, topping[i]);

		if (lmap.size() == rmap.size())
			++answer;
	}

	return answer;
}