#include <iostream>
using namespace std;
int main() {
	int a, b;
	
	cin >> a >> b;
	
	cout << (int)((float)a * (1.f + (float)b / (float)30)) << "\n";
	return 0;
}