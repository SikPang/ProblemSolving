#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int sizeOfToping, priceOfDough, priceOfToping, calorieOfDough;
	cin >> sizeOfToping >> priceOfDough >> priceOfToping >> calorieOfDough;

	vector<int> calories(sizeOfToping);
	for (int i=0; i<sizeOfToping; ++i)
		cin >> calories[i];
	
	sort(calories.begin(), calories.end(), greater<int>());
	float prev = calorieOfDough / priceOfDough;
	int sumCalorie = calorieOfDough;
	int sumPrice = priceOfDough;
	for (int i=0; i<calories.size(); ++i)
	{
		sumCalorie += calories[i];
		sumPrice += priceOfToping;
		float cur = sumCalorie / sumPrice;
		if (cur < prev)
			break;
		prev = cur;
	}
	cout << static_cast<int>(prev) << "\n";
}