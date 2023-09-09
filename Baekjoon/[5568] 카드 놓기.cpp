#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<string>& vec, vector<bool>& isUsed, unordered_set<string>& dup, int depth, int max, vector<string>& buf)
{
	if (depth == max)
	{
		string str = "";
		for (int i=0; i<buf.size(); ++i)
			str += buf[i];
		dup.insert(str);
		return;
	}

	for (int i=0; i<vec.size(); ++i)
	{
		if (isUsed[i])
			continue;
		
		isUsed[i] = true;
		buf[depth] = vec[i];
		dfs(vec, isUsed, dup, depth + 1, max, buf);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<string> vec(n);
	for (int i=0; i<vec.size(); ++i)
		cin >> vec[i];

	unordered_set<string> dup;
	vector<bool> isUsed(n);
	vector<string> buf(k);
	dfs(vec, isUsed, dup, 0, k, buf);
	cout << dup.size() << "\n";
}