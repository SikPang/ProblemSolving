#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
	vector<int> hallOfFame;
	answer.reserve(score.size());
	hallOfFame.reserve(k + 1);

	for (int i = 0; i < score.size(); ++i)
	{
		if (hallOfFame.size() < k || hallOfFame.back() < score[i])
		{
			hallOfFame.push_back(score[i]);
			sort(hallOfFame.begin(), hallOfFame.end(), greater<int>());
			if (hallOfFame.size() > k)
				hallOfFame.pop_back();
		}
		answer.push_back(hallOfFame.back());
	}

    return answer;
}