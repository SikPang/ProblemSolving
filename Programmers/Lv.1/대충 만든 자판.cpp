#include <string>
#include <vector>
#define MAX 101
#define SIZE 91

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
	answer.reserve(targets.size());

	int alpha[SIZE];

	std::fill_n(alpha, SIZE, MAX);
	
	for (int i = 0; i < keymap.size(); ++i)
	{
		for (int j = 0; j < keymap[i].length(); ++j)
		{
			if (alpha[keymap[i][j]] > j + 1)
				alpha[keymap[i][j]] = j + 1;
		}
	}

	for (int i = 0; i < targets.size(); ++i)
	{
		int sum = 0;

		for (int j = 0; j < targets[i].length(); ++j)
		{
			if (alpha[targets[i][j]] == MAX)
			{
				sum = -1;
				break;
			}
			sum += alpha[targets[i][j]];
		}
		answer.push_back(sum);
	}

    return answer;
}