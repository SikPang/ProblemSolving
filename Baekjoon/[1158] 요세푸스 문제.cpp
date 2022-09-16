#include <vector>
#include <iostream>
using namespace std;

vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;

	for (int i = 1; i < n + 1; ++i)
		vec.push_back(i);

	int index=0;
	cout << '<';
	while (!vec.empty())
	{
		index += k;

		if (index % vec.size() != 0)
			index = index % vec.size() - 1;
		else
			index = vec.size()-1;

		cout << vec[index];
		if(vec.size() != 1)
			cout << ", ";

		vec.erase(vec.begin()+index);
	}
	cout << '>';
}