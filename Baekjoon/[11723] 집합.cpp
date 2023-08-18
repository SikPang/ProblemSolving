#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_set<int> set;
	unordered_set<int> full = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		string inputStr;
		int inputNum;
		
		cin >> inputStr;
		if (inputStr != "all" && inputStr != "empty")
		{
			cin >> inputNum;
			if (inputStr == "add")
				set.insert(inputNum);
			else if (inputStr == "remove")
				set.erase(inputNum);
			else if (inputStr == "check")
			{
				if (set.find(inputNum) == set.end())
					cout << "0\n";
				else
					cout << "1\n";
			}
			else if (inputStr == "toggle")
			{
				if (set.find(inputNum) == set.end())
					set.insert(inputNum);
				else
					set.erase(inputNum);
			}
		}
		else if (inputStr == "all")
			set = full;
		else if (inputStr == "empty")
			set.clear();
	}
}