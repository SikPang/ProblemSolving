#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	int isSkip['z' + 1] = {};

	for (int i = 0; i < skip.length(); ++i)
		isSkip[skip[i]] = 1; 
	
	for (int i = 0; i < s.length(); ++i)
	{
		int cnt = 0;
		while (cnt < index)
		{
			if (s[i] == 'z')
				s[i] = 'a' - 1;

			if (!isSkip[s[i] + 1])
				++cnt; 
			++s[i];
		}
	}

    return s;
}