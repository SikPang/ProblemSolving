string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
	int curIdxC1 = 0;
	int curIdxC2 = 0;

	for (int i = 0; i < goal.size(); ++i)
	{
		if (goal[i] == cards1[curIdxC1])
			++curIdxC1;
		else if (goal[i] == cards2[curIdxC2])
			++curIdxC2;
		else
			answer = "No";
	}

	if (answer.empty())
		answer = "Yes";
	
    return answer;
}