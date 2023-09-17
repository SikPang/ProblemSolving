#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string time;
	cin >> time;

	if (time.empty())
	{
		cout << "0\n";
		return 0;
	}

	int zeroCnt = time[0] == '0' ? 1 : 0;
	int oneCnt = time[0] == '0' ? 0 : 1;
	bool isZero = time[0] == '0' ? true : false;
	
	for (int i=1; i<time.length(); ++i)
	{
		if (isZero && time[i] == '1')
		{
			++oneCnt;
			isZero = false;
		}
		else if (!isZero && time[i] == '0')
		{
			++zeroCnt;
			isZero = true;
		}
	}
	cout << min(zeroCnt, oneCnt) << "\n";
}