#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) 
{
	int order_index = 0;
	stack<int> assist;
	
	for (int i = 1; i <= order.size(); ++i)
	{
		if (order[order_index] != i)
		{
			if (assist.empty() || assist.top() != order[order_index])
				assist.push(i);
			else
			{
				assist.pop();
				++order_index;
				--i;
			}
		}
		else
			++order_index;
	}

	while (!assist.empty() && assist.top() == order[order_index])
	{
		assist.pop();
		++order_index;
	}

	return order_index;
}