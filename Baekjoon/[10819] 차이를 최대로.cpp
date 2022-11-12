#include <climits>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

vector<int> nums;
vector<bool> isUsed;
vector<int> selected;
int maxNum = INT_MIN;

int Calculate()
{
	int result = 0;

	for (int i = 0; i < selected.size() - 1; ++i)
		result += abs(selected[i] - selected[i + 1]);

	return result;
}

void FindMax(int depth)
{
	if (depth == nums.size())
	{
		int result = Calculate();
		if (result > maxNum)
			maxNum = result;
		return;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (isUsed[i]) continue;
		selected.push_back(nums[i]);
		isUsed[i] = true;

		FindMax(depth + 1);

		selected.pop_back();
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int input;

		cin >> input;
		nums.push_back(input);
		isUsed.push_back(false);
	}

	FindMax(0);

	cout << maxNum;
}