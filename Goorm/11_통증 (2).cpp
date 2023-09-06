#include <vector>
#include <iostream>
using namespace std;

#define ARR_MAX 1000000

void fill(int* dp, int a, int b, int pain, int cur)
{
	vector<int> stack;
	stack.reserve(pain);
	stack.push_back(0);

	while (!stack.empty())
	{
		int cur = stack.back();
		stack.pop_back();

		if (cur > pain)
			continue;
		if (cur + a <= pain && (dp[cur + a] == 0 || dp[cur + a] > dp[cur] + 1))
		{
			dp[cur + a] = dp[cur] + 1;
			stack.push_back(cur + a);
		}
		if (cur + b <= pain && (dp[cur + b] == 0 || dp[cur + b] > dp[cur] + 1))
		{
			dp[cur + b] = dp[cur] + 1;
			stack.push_back(cur + b);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int pain;
	int a, b;
	cin >> pain >> a >> b;
	
	int dp[ARR_MAX + 1] = {};
	dp[0] = 1;

	fill(dp, a, b, pain, 0);
	
	dp[pain] != 0 ? cout << dp[pain] - 1 << "\n" : cout << "-1\n";
}