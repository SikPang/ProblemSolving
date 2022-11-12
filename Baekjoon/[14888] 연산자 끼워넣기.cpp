#include <climits>
#include <vector>
#include <iostream>
using namespace std;

vector<int> operators;
vector<int> nums;
int maxDepth;
int minSum = INT_MAX;
int maxSum = INT_MIN;
int sum;

void Calculate(int oper, int curNum)
{
	switch (oper)
	{
	case 0:
		sum += curNum;
		break;
	case 1:
		sum -= curNum;
		break;
	case 2:
		sum *= curNum;
		break;
	case 3:
		sum /= curNum;
		break;
	}
}

void FindAnswer(int depth)
{
	if (depth == maxDepth)
	{
		if (sum > maxSum)
			maxSum = sum;
		if (sum < minSum)
			minSum = sum;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (operators[i] == 0) continue;
		int temp = sum;

		--operators[i];
		Calculate(i, nums[depth + 1]);

		FindAnswer(depth + 1);

		++operators[i];
		sum = temp;
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
	}
	for (int i = 0; i < 4; ++i)
	{
		int input;

		cin >> input;
		operators.push_back(input);
		maxDepth += input;
	}

	sum = nums[0];
	FindAnswer(0);

	cout << maxSum << '\n' << minSum;
}