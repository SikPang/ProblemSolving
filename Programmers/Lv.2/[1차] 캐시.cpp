#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

string ToUpperCase(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return str;
}

int solution(int cacheSize, vector<string> cities) 
{
	list<string> cache;
	unordered_map<string, bool> map;
	int answer = 0;

	if (cacheSize == 0)
	{
		answer = cities.size() * 5;
		return answer;
	}

	for (int i = 0; i < cities.size(); ++i)
	{
		cities[i] = ToUpperCase(cities[i]);
		if (map.find(cities[i]) != map.end())
		{
			cache.erase(find(cache.begin(), cache.end(), cities[i]));
			answer += 1;
		}
		else
		{
			if (cache.size() == cacheSize)
			{
				map.erase(cache.back());
				cache.pop_back();
			}
			map.insert({ cities[i] , 1 });
			answer += 5;
		}
		cache.push_front(cities[i]);
	}

	return answer;
}