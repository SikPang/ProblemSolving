#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pair<unsigned long long, unsigned long long> dp[41] = {};
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);

	for (int i = 2; i < 41; ++i)
		dp[i] = make_pair(dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second);

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int input;
		cin >> input;

		cout << dp[input].first << " " << dp[input].second << "\n";
	}
}