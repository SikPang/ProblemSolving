#include <iostream>
using namespace std;

int calculate(int input1, int input2, char oper)
{
	switch(oper)
	{
		case '+':
			return input1 + input2;
		case '-':
			return input1 - input2;
		case '*':
			return input1 * input2;
		case '/':
			return input1 / input2;
	}
}

int main() {
	int num;
	int sum = 0;
	
	cin >> num;
	
	for (int i = 0; i < num; ++i)
	{
		int input1, input2;
		char oper;
		
		cin >> input1 >> oper >> input2;
		
		sum += calculate(input1, input2, oper);
	}
	cout << sum << "\n";
	
	return 0;
}