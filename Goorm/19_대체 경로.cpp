#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector< vector<int> >& graph, int start, int end, int construction)
{
	queue< pair<int, int> > que;
	vector<int> isVisited(graph.size());

	que.push(make_pair(start, 1));
	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur.first].size(); ++i)
		{
			if (isVisited[graph[cur.first][i]] || graph[cur.first][i] == construction)
				continue;
			
			if (graph[cur.first][i] == end)
			{
				cout << cur.second + 1 << "\n";
				return;
			}
			isVisited[graph[cur.first][i]] = true;
			que.push(make_pair(graph[cur.first][i], cur.second + 1));
		}
	}
	cout << "-1\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s, e;
	cin >> n >> m >> s >> e;

	vector< vector<int> > graph(n + 1);
	for (int i=0; i<m; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i=1; i<n+1; ++i)
	{
		if (i == s || i == e)
		{
			cout << "-1\n";
			continue;
		}
		bfs(graph, s, e, i);
	}
}