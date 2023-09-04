#include <queue>
#include <vector>
#include <iostream>
#define VISITED 0
using namespace std;

void bfs(vector< vector<int> >& graph, int cur)
{
	queue<int> que;
	que.push(cur);

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		graph[cur][VISITED] = 1;

		for (int i=1; i<graph[cur].size(); ++i)
		{
			if (graph[cur][i] == 1 && graph[i][cur] == 1)
			{
				que.push(i);
				graph[i][cur] = 0;
			}
			graph[cur][i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int sizeOfNode, sizeOfLink;
	cin >> sizeOfNode >> sizeOfLink;

	vector< vector<int> > graph(sizeOfNode + 1);
	for (int i=0; i<graph.size(); ++i)
		graph[i].resize(sizeOfNode + 1);

	for (int i=0; i<sizeOfLink; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}

	int answer = 0;
	for (int i=1; i<graph.size(); ++i)
	{
		if (graph[i][VISITED] == 1)
			continue;
		bfs(graph, i);
		++answer;
	}
	cout << answer << "\n";
}