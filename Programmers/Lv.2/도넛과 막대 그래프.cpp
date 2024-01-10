#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;
vector<int> answer(4);

struct Node
{
	vector<int> list;
	int popularPoint;
	Node() : list(), popularPoint(0) {}
};

enum class Kind
{
	None, Donut, Stick, Eight
};

void bfs(unordered_map<int, Node>& graph, int start)
{
	queue<int> que;
	auto curNode = graph.find(start);
	unordered_set<int> nodes = {start};
	int edges = 0;

	que.push(start);
	while (!que.empty())
	{
		auto curNode = graph.find(que.front());
		que.pop();
		
		vector<int>& list = curNode->second.list;
		edges += list.size();
		for (int i=0; i<list.size(); ++i)
		{
			if (nodes.find(list[i]) == nodes.end())
			{
				que.push(list[i]);
				nodes.insert(list[i]);
			}
		}
		if (que.front() == start)
			break;
	}

	// 도넛 : n개의 정점, n개의 간선
	// 막대 : n개의 정점, n-1개의 간선
	// 8자  : n개의 정점, n+1개의 간선
	if (nodes.size() == edges)
		++answer[(int)Kind::Donut];
	else if (nodes.size() == edges + 1)
		++answer[(int)Kind::Stick];
	else if (nodes.size() == edges - 1)
		++answer[(int)Kind::Eight];
}

vector<int> solution(vector<vector<int>> edges) {
	unordered_map<int, Node> graph;

	for (int i=0; i<edges.size(); ++i)
	{
		graph[edges[i][0]].list.push_back(edges[i][1]);
		++graph[edges[i][1]].popularPoint;
	}
	
	// 임의의 정점 : 가는게 2개 이상이고 오는게 없음
	unordered_map<int, Node>::iterator criminal;
	for (unordered_map<int, Node>::iterator suspect=graph.begin(); suspect!=graph.end(); ++suspect)
	{
		if (suspect->second.list.size() >= 2 && suspect->second.popularPoint == 0)
		{
			criminal = suspect;
			answer[0] = suspect->first;
			break;
		}
	}

	vector<int>& list = criminal->second.list;
	for (int i=0; i<list.size(); ++i)
		bfs(graph, list[i]);
    return answer;
}