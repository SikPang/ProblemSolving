#include <string>
#include <unordered_map>
using namespace std;

void ToUpperCase(string *str)
{
	for (int i=0; i<(*str).size(); ++i)
	{
		if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
			(*str)[i] -= 32;
	}
}

int solution(string str1, string str2) 
{
	unordered_map<string, int> map;
	int interNum = 0;
	int unionNum = 0;

	ToUpperCase(&str1);
	ToUpperCase(&str2);

	for (int i = 0; i < str1.size() - 1; ++i)
	{
		if ((str1[i] < 'A' || str1[i] > 'Z') || (str1[i + 1] < 'A' || str1[i + 1] > 'Z'))
			continue;

		string temp;
		temp += str1[i];
		temp += str1[i + 1];

		if (map.find(temp) != map.end())	// found
			++map[temp];
		else
			map.insert(make_pair(temp, 1));
		++unionNum;
	}
	
	for (int i = 0; i < str2.size() - 1; ++i)
	{
		if ((str2[i] < 'A' || str2[i] > 'Z') || (str2[i + 1] < 'A' || str2[i + 1] > 'Z'))
			continue;

		string temp;
		temp += str2[i];
		temp += str2[i + 1];

		if (map.find(temp) != map.end())	// found
		{
			--map[temp];
			if (map[temp] == 0)
				map.erase(temp);
			++interNum;
		}
		++unionNum;
	}

	if (unionNum == 0)
		return 65536;
    
	unionNum -= interNum;
	return (double)interNum / unionNum * 65536;
}