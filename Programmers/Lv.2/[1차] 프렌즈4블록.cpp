#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) 
{
	int answer = 0;
	bool pop;

	vector<string> new_board;

	for (int i = 0; i < n; ++i)
	{
		string temp;
		for (int j = m - 1; j >= 0; --j)
		{
			temp += board[j][i];
		}
		new_board.push_back(temp);
	}
	vector<string> check(new_board);

	while (true)
	{
		pop = false;

		for (int i = 0; i < new_board.size() - 1; ++i)
		{
			for (int j = 0; j < new_board[0].size() - 1; ++j)
			{
				if (new_board[i][j] == '0' || new_board[i][j] == '1') continue;

				if (new_board[i][j] == new_board[i + 1][j] && new_board[i][j] == new_board[i][j + 1]
					&& new_board[i][j] == new_board[i + 1][j + 1])
				{
					check[i][j] = '0';
					check[i + 1][j] = '0';
					check[i][j + 1] = '0';
					check[i + 1][j + 1] = '0';
					pop = true;
				}
			}
		}

		if (!pop) break;

		for (int i = 0; i < check.size(); ++i)
		{
			for (int j = 0; j < check[0].size(); ++j)
			{
				if (check[i][j] == '0')
				{
					++answer;
					check[i].erase(j, 1);
					check[i] += '1';
					--j;
				}
			}
		}

		copy(check.begin(), check.end(), new_board.begin());
	}

	return answer;
}