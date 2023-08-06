int solution(string s) {
    int answer = 0;
	int xCnt = 0;
	int notXCnt = 0;
	int i = 0;

	while (i < s.length())
	{
		char x = s[i];

		do
		{
			if (s[i] == x)
				++xCnt;
			else
				++notXCnt;
			++i;
		} while (xCnt != notXCnt);
		
		++answer;
	}

    return answer;
}