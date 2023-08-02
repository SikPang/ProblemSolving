
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
		if (hallOfFame.empty() || hallOfFame.back() < score[i])
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

int main()
{
	vector<int> input1;
	input1.push_back(0);
	input1.push_back(10);
	input1.push_back(20);
	input1.push_back(30);
	input1.push_back(40);
	input1.push_back(50);
	input1.push_back(60);

	vector<int> ans = solution(5, input1);
	for (int i = 0; i < ans.size(); ++i)
		std::cout << ans[i] << " ";
	std::cout << "\n";

	// vector<int> ans2 = solution("foobar");
	// for (int i = 0; i < ans2.size(); ++i)
	// 	std::cout << ans2[i] << " ";
	// std::cout << "\n";

	// cout << solution("3141592", "271") << "\n";
	// cout << solution("500220839878", "7") << "\n";
	// cout << solution("10203", "15") << "\n";
	// cout << solution("9999999", "99") << "\n";
}