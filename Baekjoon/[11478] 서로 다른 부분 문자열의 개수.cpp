#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<string, bool> map;
	int total = 0;

	string str;
	cin >> str;

	for (int i = 1; i < str.size() + 1; ++i)
	{
		int j = 0;
		while (j < str.size())
		{
			string temp = str.substr(j, i);
			if (map.find(temp) == map.end())
			{
				map.insert(make_pair( temp, true ));
				++total;
			}
			++j;
		}
	}
	std::cout << total;
}