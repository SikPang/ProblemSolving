#include <iostream>
using namespace std;

int main() {
	int num, hour, minute;
	
	cin >> num >> hour >> minute;
	
	for (int i = 0; i < num; ++i)
	{
		int input;
		cin >> input;
		
		minute += input;
		hour = (hour + minute / 60) % 24;
		minute = minute % 60;
	}
	
	cout << hour << " " << minute << "\n";
	return 0;
}
