#include <string>
#include <iostream>
using namespace std;

void fill(string& board, int& start, int len, char c)
{
	for (int i=start; i<start+len; ++i)
		board[i] = c;
	start += len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string board;
	cin >> board;

	for (int i=0; i<board.length(); ++i)
	{
		int emptyLen = 0;
		for (int j=i; j<board.length(); ++j)
		{
			if (board[j] == '.')
				break;
			++emptyLen;
		}

		for (int j=0; j<emptyLen/4; ++j)
			fill(board, i, 4, 'A');
		emptyLen %= 4;
		for (int j=0; j<emptyLen/2; ++j)
			fill(board, i, 2, 'B');
		
		if (emptyLen % 2 != 0)
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << board << "\n";
}