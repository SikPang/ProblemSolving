#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
	answer.reserve(photo.size());

	unordered_map<string, int> score;
	for (int i = 0; i < name.size(); ++i)
		score.insert(make_pair(name[i], yearning[i]));

	for (int i = 0; i < photo.size(); ++i)
	{
		int sum = 0;

		for (int j = 0; j < photo[i].size(); ++j)
		{
			unordered_map<string, int>::iterator iter = score.find(photo[i][j]);

			if (iter != score.end())
				sum += iter->second;
		}

		answer.push_back(sum);
	}
	
    return answer;
}