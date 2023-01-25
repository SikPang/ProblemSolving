#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

long long answer = 0;
vector< pair<char, int> > oper_kind;

long long calculate(vector<long long> nums, vector<char> oper_all)
{
	for (int j = 0; j < oper_kind.size(); ++j)
	{
		vector<long long>::iterator num_iter = nums.begin();
		vector<char>::iterator oper_iter = oper_all.begin();
		char ch;

		for (int i = 0; i < oper_kind.size(); ++i)
		{
			if (oper_kind[i].second == j + 1)
				ch = oper_kind[i].first;
		}

		for (int i = 0; i < oper_all.size(); ++i)
		{
			if (oper_all[i] == ch)
			{
				oper_iter = oper_all.erase(oper_iter);
				
				if (ch == '*')
					nums[i + 1] = nums[i] * nums[i + 1];
				else if (ch == '+')
					nums[i + 1] = nums[i] + nums[i + 1];
				else if (ch == '-')
					nums[i + 1] = nums[i] - nums[i + 1];

				num_iter = nums.erase(num_iter);
				--i;
			}
			else
			{
				++num_iter;
				++oper_iter;
			}
		}
	}

	if (nums[0] >= 0)
		return nums[0];
	else
		return -nums[0];
}

void recursion(int depth, vector<long long>& nums, vector<char>& oper_all)
{
	if (depth == oper_kind.size())
	{
		long long value = calculate(nums, oper_all);

		if (value > answer)
			answer = value;

		return;
	}

	for (int i = 0; i < oper_kind.size(); ++i)
	{
		if (oper_kind[i].second > 0)
			continue;

		oper_kind[i].second = depth + 1;

		recursion(depth + 1, nums, oper_all);

		oper_kind[i].second = 0;
	}
}

long long solution(string expression) 
{
	unordered_set<char> set;
	vector<long long> nums;
	vector<char> oper_all;
	string temp;

	for (int i = 0; i < expression.size(); ++i)
	{
		if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-')
		{
			oper_all.push_back(expression[i]);
			nums.push_back(stoll(temp));
			temp.clear();
			if (set.find(expression[i]) == set.end())
				set.insert(expression[i]);
		}
		else
			temp += expression[i];
	}
	nums.push_back(stoi(temp));

	for (char ch : set)
		oper_kind.push_back(make_pair(ch, 0));

	recursion(0, nums, oper_all);

	return answer;
}