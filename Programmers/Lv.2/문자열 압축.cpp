#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int minLen = 1001;

	if (s.length() == 1)
		return 1;

	for (int curNum = 1; curNum <= s.length() / 2; ++curNum)
	{
		string result = "";
		string prev = "";
		string cur = "";
		int cnt = 1;

		for (int i = 0; i < s.length(); i+=curNum)
		{
			cur = s.substr(i, curNum);
			if (prev == cur)
				++cnt;
			else if (!prev.empty())
			{
				result += (cnt == 1 ? "" : to_string(cnt)) + prev;
				cnt = 1;
			}
			prev = cur;
		}
		result += (cnt == 1 ? "" : to_string(cnt)) + prev;

		if (result.length() < minLen)
			minLen = result.length();
		result.clear();
		prev.clear();
	}
	return minLen;
}