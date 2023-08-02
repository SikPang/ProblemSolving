#include <string>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
	size_t pNum = stoull(p);

	for (size_t i = 0; i < t.length(); ++i)
	{
		if (i + p.length() > t.length())
			break;
		
		size_t tNum = stoull(t.substr(i, p.length()));
		if (tNum <= pNum)
			++answer;
	}

    return answer;
}