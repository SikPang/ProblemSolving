#include <iostream>
#include <string>
#include <set>
using namespace std;

void dfs(string& str, string& buf, set<string>& dup, set<string>& answer, int k, int depth, int idx)
{
	if (depth == k)
	{
		if (dup.find(buf) == dup.end())
			dup.insert(buf);
		else
			answer.insert(buf);
		return;
	}
	for (int i=idx; i<str.length(); ++i)
	{
		buf[depth] = str[i];
		dfs(str, buf, dup, answer, k, depth + 1, i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string strs[3];
	int k;
	cin >> strs[0] >> strs[1] >> strs[2] >> k;

	set<string> dup;
	set<string> answer;
	for (int i=0; i<3; ++i)
	{
		string buf;
		buf.resize(k);
		dfs(strs[i], buf, dup, answer, k, 0, 0);
	}

	if (answer.size() == 0)
		cout << "-1\n";
	else
	{
		for (set<string>::iterator iter=answer.begin(); iter!=answer.end(); ++iter)
			cout << *iter << "\n";
	}
}