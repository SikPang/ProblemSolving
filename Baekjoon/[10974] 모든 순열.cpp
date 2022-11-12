#include <vector>
#include <iostream>
using namespace std;

vector<int> nums;
vector<bool> isUsed;
vector<int> selected;

void FindPermutation(int depth)
{
	if (depth == nums.size())
	{
		for (int i = 0; i < selected.size(); ++i)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (isUsed[i]) continue;
		selected.push_back(nums[i]);
		isUsed[i] = true;

		FindPermutation(depth + 1);

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
	for (int i = 1; i <= n; ++i)
	{
		nums.push_back(i);
		isUsed.push_back(false);
	}

	FindPermutation(0);
}