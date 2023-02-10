#include <stack>
#include <string>
#include <vector>

using namespace std;

bool is_correct(string& p)
{
	if (p.empty())
		return true;

	stack<char> stack;

	stack.push(p[0]);
	for (int i = 1; i < p.size(); ++i)
	{
		if (p[i] == ')' && !stack.empty() && stack.top() == '(')
			stack.pop();
		else
			stack.push(p[i]);
	}

	if (stack.empty())
		return true;
	else
		return false;
}

int get_balanced_len(string& p)
{
	int open_p = 0;
	int close_p = 0;

	for (int i = 0; i < p.size(); ++i)
	{
		if (open_p != 0 && close_p != 0 && open_p == close_p)
			return i;

		if (p[i] == '(')
			++open_p;
		else
			++close_p;
	}
	return p.size();
}

string get_correct(string v)
{
	if (v.empty())
		return "";
	
	int len = get_balanced_len(v);
	string temp_u = v.substr(0, len);
	string temp_v = v.substr(len, v.size() - len);

	if (is_correct(temp_u))
		return temp_u + get_correct(temp_v);
	else
	{
		temp_u = temp_u.substr(1, len - 2);
		for (int i = 0; i < temp_u.size(); ++i)
		{
			if (temp_u[i] == '(')
				temp_u[i] = ')';
			else
				temp_u[i] = '(';
		}
		return '(' + get_correct(temp_v) + ')' + temp_u;
	}
}

string solution(string p) 
{
	string answer = "";

	if (is_correct(p))
		return p;

	answer = get_correct(p);

	return answer;
}