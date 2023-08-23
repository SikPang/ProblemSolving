#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int answer = 0;
	int num;
	cin >> num;

	while (num > 0)
	{
		if (num >- 14)
			num -= 14;
		else if (num >- 7)
			num -= 7;
		else
			num -= 1;
		++answer;
	}
	cout << answer << "\n";
}