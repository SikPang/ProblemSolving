#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#define SIZE 4

using namespace std;

void pushElements(vector<vector<string>>& keys, unordered_map<string, vector<int>>& category, vector<string>& buf, int score, int depth)
{
	if (depth == SIZE)
	{
		string key = "";
		for (int i=0; i<SIZE; ++i)
			key += buf[i];
		category[key].push_back(score);
		return;
	}

	for (int i=0; i<2; ++i)
	{
		buf.push_back(keys[depth][i]);
		pushElements(keys, category, buf, score, depth + 1);
		buf.pop_back();
	}
}

vector<int> solution(vector<string> info, vector<string> query) 
{
	unordered_map<string, vector<int>> category;
	vector<int> answer(query.size());

	string temp;
	for (int i=0; i<info.size(); ++i)
	{
		stringstream ss(info[i]);
		vector<vector<string>> keys(SIZE, vector<string>(2));

		for (int j=0; j<SIZE; ++j)
		{
			getline(ss, temp, ' ');
			keys[j][0] = temp;
			keys[j][1] = "-";
		}

		getline(ss, temp, ' ');
		vector<string> buf;
		pushElements(keys, category, buf, stoi(temp), 0);
	}

	for (auto iter=category.begin(); iter!=category.end(); ++iter)
		sort(iter->second.begin(), iter->second.end());

	for (int i=0; i<query.size(); ++i)
	{
		stringstream ss(query[i]);
		string key = "";

		for (int j=0; j<SIZE*2-1; ++j)
		{
			getline(ss, temp, ' ');
			if (temp == "and")
				continue;
			key += temp;
		}

		auto iter = category.find(key);
        if (iter == category.end())
            continue;

		getline(ss, temp, ' ');
		auto found = lower_bound(iter->second.begin(), iter->second.end(), stoi(temp));
		answer[i] = iter->second.end() - found;
	}
	return answer;
}