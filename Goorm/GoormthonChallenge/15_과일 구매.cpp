#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int fruitSize, money;
	cin >> fruitSize >> money;

	vector< pair< int, int> > fruits;
	fruits.reserve(fruitSize);
	for (int i=0; i<fruitSize; ++i)
	{
		int price, amount;
		cin >> price >> amount;
		fruits.push_back(make_pair(amount / price, price));
	}
	
	sort(fruits.begin(), fruits.end());

	long long answer = 0;
	for (int i=fruits.size()-1; i>=0; --i)
	{
		for (int j=0; j<fruits[i].second; ++j)
		{
			if (money == 0)
			{
				cout << answer << "\n";
				return 0;
			}
			answer += fruits[i].first;
			--money;
		}
	}
	cout << answer << "\n";
}