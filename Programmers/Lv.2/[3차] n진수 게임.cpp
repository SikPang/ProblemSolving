#include <string>

using namespace std;

string cur_str;
string hexs = "0123456789ABCDEF";

void get_num(int num, int n)
{
	if (num == 0) return;

	get_num(num / n, n);
	cur_str += hexs[num % n];
}

string solution(int n, int t, int m, int p)
{
	string answer = "";
	int cur_num = 0;
	int turn = 1;

	while (answer.size() < t)
	{
		if (cur_str.empty())
		{
			get_num(cur_num, n);
			if (cur_str.empty())
				cur_str += '0';
			++cur_num;
		}

		if ((m == p && turn % m == 0) || (m != p && (turn % m) - p == 0))
			answer += cur_str[0];

		cur_str.erase(0, 1);
		++turn;
	}

	return answer;
}