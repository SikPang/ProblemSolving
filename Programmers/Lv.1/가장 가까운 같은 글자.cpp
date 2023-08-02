#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
	answer.reserve(s.length());

	for (int i = 0; i < s.length(); ++i)
	{
		char target = s[i];
		int pos = -1;

		for (int j = i - 1; j >= 0; --j)
		{
			if (s[j] == target)
			{
				pos = j;
				break;
			}
		}

		if (pos == -1)
			answer.push_back(-1);
		else
			answer.push_back(i - pos);
	}

    return answer;
}