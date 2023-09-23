#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmpStr(string& a, string& b)
{
	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> input(n);
	for (int i=0; i<n; ++i)
		cin >> input[i];
	sort(input.begin(), input.end(), cmpStr);

	vector<bool> isUsed(n);
	for (int i=0; i<n; ++i)
	{
		for (int j=i+1; j<n; ++j)
		{
			if (input[j].substr(0, input[i].size()) == input[i])
			{
				isUsed[j] = true;
				break;
			}
		}
	}
	cout << count(isUsed.begin(), isUsed.end(), false) << "\n";
}