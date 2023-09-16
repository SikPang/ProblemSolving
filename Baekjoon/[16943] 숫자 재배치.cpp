#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void dfs(string& str, string& buf, string& isUsed, string& target, string& answer, int depth)
{
	if (depth == str.length())
	{
		int bufNum = stoi(buf);
		if (to_string(bufNum).length() == buf.length() && bufNum < stoi(target))
			answer = buf;
		return;
	}
	for (int i=0; i<str.length(); ++i)
	{
		if (isUsed[i] == 1)
			continue;
		isUsed[i] = 1;
		buf[depth] = str[i];
		dfs(str, buf, isUsed, target, answer, depth + 1);
		isUsed[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	sort(a.begin(), a.end());
	string buf;
	string isUsed;
	string answer = "";
	buf.resize(a.length());
	isUsed.resize(a.length());

	dfs(a, buf, isUsed, b, answer, 0);
	if (answer.empty())
		cout << "-1\n";
	else
		cout << stoi(answer) << "\n";
}