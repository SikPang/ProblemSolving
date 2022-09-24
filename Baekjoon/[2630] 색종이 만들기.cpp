#include <iostream>
using namespace std;
int arr[128][128] = {};
int answer[2] = {};

bool CheckPaper(int n, int row, int col, int currentNum)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(arr[row+i][col+j] != currentNum)
				return false;
	return true;
}

void Recursive(int n, int row, int col)
{
	if (n == 0) return;

	if (CheckPaper(n, row, col, arr[row][col]))
		++answer[arr[row][col]];
	else 
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				Recursive(n/2, row+(i*n/2), col+(j*n/2));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			int data;
			cin >> data;
			arr[i][j] = data;
		}
	}

	Recursive(num, 0, 0);

	for(int i=0; i<2; ++i)
		cout << answer[i] << '\n';
}