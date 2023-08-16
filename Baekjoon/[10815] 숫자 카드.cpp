#include <iostream>
#include <unordered_set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::unordered_set<int> uset;
    int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int input;
		std::cin >> input;
		uset.insert(input);
	}

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int input;
		std::cin >> input;
		if (uset.find(input) != uset.end())
			std::cout << "1 ";
		else
			std::cout << "0 ";
	}
	std::cout << "\n";
}