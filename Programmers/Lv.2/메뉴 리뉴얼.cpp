#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> candidate[11];
string pick;

void find_course(int depth, int max, string &order, int index)
{
	if (depth == max)
	{
		if (candidate[max].find(pick) != candidate[max].end())
			++candidate[max][pick];
		else
			candidate[max].insert(make_pair(pick, 1));
		return;
	}

	for (int i = index; i < order.size(); ++i)
	{
		pick += order[i];

		find_course(depth + 1, max, order, i + 1);

		pick.erase(pick.size()-1);
	}
}

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) 
{
	vector<string> answer;

	for (int i=0; i<orders.size(); ++i)
		sort(orders[i].begin(), orders[i].end());

	for (int i = 0; i < orders.size(); ++i)
		for (int j = 0; j < course.size(); ++j)
			find_course(0, course[j], orders[i], 0);

	for (int i = 0; i < course.size(); ++i)
	{
		if (candidate[course[i]].size() == 0) continue;
		vector< pair<string, int> > temp(candidate[course[i]].begin(), candidate[course[i]].end());
		
		sort(temp.begin(), temp.end(), cmp);
		int max = temp[0].second;
        if (max < 2) continue;

		for (int j = 0; j < temp.size(); ++j)
		{
			if (temp[j].second < max)
				break;
			answer.push_back(temp[j].first);
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}