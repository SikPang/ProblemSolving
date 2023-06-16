#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int max;
    std::cin >> max;

	std::vector<int> stack;
	std::string answer;
	stack.reserve(max);
	answer.reserve(max * 2);

	int cur = 1;
	for (int i = 0; i < max; ++i)
	{
		int input;
		std::cin >> input;

		while (cur <= input)
		{
			stack.push_back(cur);
			answer += "+\n";
			++cur;
		}
		if (stack.back() != input)
		{
			answer = "NO";
			break;
		}
		stack.pop_back();
		answer += "-\n";
	}
	std::cout << answer;
}
