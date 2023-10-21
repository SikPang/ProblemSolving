#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);
vector<int> percent{10, 20, 30, 40};
vector<int> selectedPercent;

// depth 하나마다 이모티콘 할인율 고르기
void dfs(vector<vector<int>>& users, vector<int>& emoticons, int depth)
{
	if (depth == emoticons.size())
	{
		// 할인율 적용 및 살 사람 체크
		vector<int> sum(users.size());
		for (int i=0; i<users.size(); ++i)
		{
			for (int j=0; j<selectedPercent.size(); ++j)
			{
				if (selectedPercent[j] >= users[i][0])
					sum[i] += emoticons[j] * (100 - selectedPercent[j]) / 100.f;
			}
		}

		int emoticonPlusCnt = 0;
		int total = 0;
		for (int i=0; i<sum.size(); ++i)
		{
			if (sum[i] >= users[i][1])
				++emoticonPlusCnt;
			else
				total += sum[i];
		}

		if (answer[0] < emoticonPlusCnt)
		{
			answer[0] = emoticonPlusCnt;
			answer[1] = total;
		}
		else if (answer[0] == emoticonPlusCnt && answer[1] < total)
			answer[1] = total;
		return;
	}
	for (int i=0; i<percent.size(); ++i)
	{
		selectedPercent[depth] = percent[i];
		dfs(users, emoticons, depth + 1);
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	selectedPercent.resize(emoticons.size());
    dfs(users, emoticons, 0);
    return answer;
}