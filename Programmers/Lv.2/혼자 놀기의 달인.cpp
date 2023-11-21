#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(vector<int>& cards, vector<bool>& isUsed, int idx)
{
    queue<int> que;
    int score = 1;
    
    que.push(idx);
    isUsed[idx] = true;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        if (isUsed[cards[cur]-1])
            break;
        ++score;
        isUsed[cards[cur]-1] = true;
        que.push(cards[cur]-1);
    }
    return score;
}

int solution(vector<int> cards) 
{
    int max = 0;
    
    for (int i=0; i<cards.size(); ++i)
    {
        vector<bool> isUsed(cards.size());
        int first = bfs(cards, isUsed, i);

		for (int j=0; j<cards.size(); ++j)
		{
			if (isUsed[j])
				continue;
			vector<bool> copy(isUsed);
			int second = bfs(cards, copy, j);
			if (max < first * second)
				max = first * second;
		}
    }
    return max;
}