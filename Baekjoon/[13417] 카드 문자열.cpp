#include <deque>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n;
	char card;
	cin >> t;

	for (int i=0; i<t; ++i)
	{
		deque<char> deq;
		cin >> n;
		for (int j=0; j<n; ++j)
		{
			cin >> card;
			if (deq.empty() || card > deq.front())
				deq.push_back(card);
			else
				deq.push_front(card);
		}
		for (int j=0; j<deq.size(); ++j)
			cout << deq[j];
		cout << "\n";
	}
}