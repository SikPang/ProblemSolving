#include <set>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int nodeSize, linkSize, curNode;
	cin >> nodeSize >> linkSize >> curNode;

	// row : node num
	// col : connected nodes
	vector< set<int> > graph(nodeSize + 1);

	for (int i=0; i<linkSize; ++i)
	{
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;

		graph[nodeA].insert(nodeB);
		graph[nodeB].insert(nodeA);
	}

	int cnt = 1;
	while (true)
	{
		set<int>::iterator dest = graph[curNode].begin();
		if (dest == graph[curNode].end())
			break;
		int destNode = *dest;
		graph[curNode].erase(dest);
		for (int i=0; i<graph.size(); ++i)
			graph[i].erase(curNode);
		curNode = destNode;
		++cnt;
	}
	cout << cnt << " " << curNode << "\n";
}