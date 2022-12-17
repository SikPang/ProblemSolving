#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec;
	string tempStr;
	int minus = 1;
	int answer = 0;

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			tempStr += str[i];
		else
		{
			if (!tempStr.empty())
			{
				vec.push_back(stoi(tempStr) * minus);
				tempStr.clear();
			}
			if (str[i] == '-')
				minus = -1;
			else
				minus = 1;
		}
	}
	vec.push_back(stoi(tempStr) * minus);

	minus = 1;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] < 0)
			minus = 1;

		answer += vec[i] * minus;

		if (vec[i] < 0)
			minus = -1;
	}

	cout << answer;
}