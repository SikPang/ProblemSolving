#include <queue>
#include <deque>
#include <iostream>
using namespace std;

int Pow(int i)
{
	int result = 1;

	while (i > 0)
	{
		result *= 2;
		--i;
	}
	return result;
}

void Spin(deque<char> *wheel, int dir)
{
	if (dir == 1)
	{
		char temp = (*wheel).back();
		(*wheel).pop_back();
		(*wheel).push_front(temp);
	}
	else
	{
		char temp = (*wheel).front();
		(*wheel).pop_front();
		(*wheel).push_back(temp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<char> wheel[4];
	queue<pair<int, int>> que;
	bool isVisited[4];
	int n;
	int answer = 0;

	for (int i = 0; i < 4; ++i)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); ++j)
			wheel[i].push_back(temp[j]);
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num, dir;
		cin >> num >> dir;

		que.push({num - 1, dir});
		for (int i = 0; i < 4; ++i)
			isVisited[i] = 0;

		while (!que.empty())
		{
			num = que.front().first;
			dir = que.front().second;
			isVisited[num] = true;

			if (num > 0 && wheel[num][6] != wheel[num - 1][2] && !isVisited[num - 1])
				que.push({ num - 1, dir * -1 });
			if (num < 3 && wheel[num][2] != wheel[num + 1][6] && !isVisited[num + 1])
				que.push({ num + 1, dir * -1 });

			Spin(&(wheel[num]), dir);
			que.pop();
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		if (wheel[i].front() == '1')
			answer += Pow(i);
	}
	cout << answer;
}