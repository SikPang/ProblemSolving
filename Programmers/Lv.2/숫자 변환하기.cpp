#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

int solution(int x, int y, int n) 
{
	queue< pair<int, int> > que;
    unordered_set<int> set;

	que.push(make_pair(x, 0));
    set.insert(x);
	while (!que.empty())
	{
		pair<int, int> num = que.front();
		que.pop();

		if (num.first == y)
			return (num.second);
        
        if (num.first + n <= y && set.find(num.first + n) == set.end())
        {
            que.push(make_pair(num.first + n, num.second + 1));
            set.insert(num.first + n);
        }
        if (num.first * 2 <= y && set.find(num.first* 2) == set.end())
        {
            que.push(make_pair(num.first * 2, num.second + 1));
            set.insert(num.first * 2);
        }
        if (num.first * 3 <= y && set.find(num.first * 3) == set.end())
        {
            que.push(make_pair(num.first * 3, num.second + 1));
            set.insert(num.first * 3);
        }
	}

	return -1;
}