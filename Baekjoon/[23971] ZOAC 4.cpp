#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double height, width, distY, distX;
	cin >> height >> width >> distY >> distX;

	int row = ceil(height / (distY + 1));
	int col = ceil(width / (distX + 1));

	cout << row * col << "\n";
}