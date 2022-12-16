#include <vector>
#include <iostream>
using namespace std;

vector<int> nums;
vector<bool> is_visited;
int sum = 0;
int answer = 0;

void find_answer(int depth, int goal)
{
	if (depth == 3)
	{
		if (goal - answer > goal - sum)
			answer = sum;
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (is_visited[i] || sum + nums[i] > goal) continue;
		
		is_visited[i] = true;
		sum += nums[i];
		find_answer(depth + 1, goal);
		is_visited[i] = false;
		sum -= nums[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		nums.push_back(num);
		is_visited.push_back(false);
	}

	find_answer(0, m);
	cout << answer;
}