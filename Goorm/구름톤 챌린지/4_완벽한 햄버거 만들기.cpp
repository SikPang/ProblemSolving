#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	
	int prevNum = 0;
	int answer = 0;
	bool isDescending = false;
	
	for (int i = 0; i < num; ++i)
	{
		int input;
		cin >> input;
		
		if (isDescending && prevNum < input)
		{
			cout << "0\n";
			return 0;
		}
		if (prevNum > input)
				isDescending = true;
		
		prevNum = input;
		answer += input;
	}
	
	cout << answer << "\n";
	return 0;
}