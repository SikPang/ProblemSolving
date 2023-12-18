#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

void initStack(stack<int>& curStack, vector<int>& places)
{
	places.insert(places.begin(), 0);
	
	for (int i=0; i<places.size(); ++i)
	{
		if (places[i] > 0)
			curStack.push(i);
	}
}

void work(stack<int>& curStack, vector<int>& places, int cap)
{
	int curBoxes = 0;

	while (!curStack.empty() && curBoxes < cap)
	{
		int& targetBoxes = places[curStack.top()];

		if (targetBoxes <= cap - curBoxes)
		{
			curBoxes += targetBoxes;
			curStack.pop();
		}
		else
		{
			targetBoxes -= cap - curBoxes;
			curBoxes = cap;
		}
	}
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    stack<int> deliverStack, pickupStack;
	long long dist = 0;
	int curBoxes;

	initStack(deliverStack, deliveries);
	initStack(pickupStack, pickups);

	while (!deliverStack.empty() || !pickupStack.empty())
	{
		if (deliverStack.empty())
			dist += pickupStack.top() * 2;
		else if (pickupStack.empty())
			dist += deliverStack.top() * 2;
		else
			dist += max(deliverStack.top(), pickupStack.top()) * 2;

		work(deliverStack, deliveries, cap);
		work(pickupStack, pickups, cap);
	}
    return dist;
}