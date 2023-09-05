#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Component
{
	vector<int> list;
	double density;
	int linkNum;

	Component(vector<int>& list, int linkNum)
		: list(list)
		, density((double)linkNum / list.size())
		, linkNum(linkNum) 
	{
		sort(this->list.begin(), this->list.end());
	}
};

bool cmp(Component& a, Component& b)
{
	if (a.density == b.density)
	{
		if (a.list.size() == b.list.size())
			return a.list.front() > b.list.front();
		else
			return a.list.size() > b.list.size();
	}
	return a.density < b.density;
}

void bfs(vector<Component>& components, vector< set<int> >& graph, vector<int>& isVisited, int cur)
{
	vector<int> buf;
	queue<int> que;
	int cnt = 0;

	que.push(cur);
	while (!que.empty())
	{
		int front = que.front();
		que.pop();

		if (isVisited[front] == 1)
			continue;

		buf.push_back(front);
		isVisited[front] = 1;
		for (set<int>::iterator iter=graph[front].begin(); iter != graph[front].end(); ++iter)
		{
			++cnt;
			graph[*iter].erase(front);
			que.push(*iter);
		}
	}
	if (buf.size() > 1)
		components.push_back(Component(buf, cnt));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int sizeOfNode, sizeOfLink;
	cin >> sizeOfNode >> sizeOfLink;

	vector< set<int> > graph(sizeOfNode + 1);
	vector<int> isVisited(sizeOfNode + 1);

	for (int i=0; i<sizeOfLink; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	vector<Component> components;
	for (int i=1; i<graph.size(); ++i)
	{
		if (isVisited[i] == 1)
			continue;
		
		bfs(components, graph, isVisited, i);
	}
	sort(components.begin(), components.end(), cmp);

	for (int i=0; i<components.back().list.size(); ++i)
		cout << components.back().list[i] << " ";
	cout << "\n";
}