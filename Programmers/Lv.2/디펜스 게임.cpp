#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
	priority_queue<int> pQue;
	
	for (int i = 0; i < enemy.size(); ++i)
	{   
		pQue.push(-enemy[i]);

		// 무적권의 개수를 넘어설 때 작은 라운드 부터 병사 소모
		if (pQue.size() > k)
		{
			n -= -pQue.top();
			pQue.pop();
		}
        
        // 병사가 0보다 작으면 클리어 실패
        if (n < 0)
			return i;
	}
	return enemy.size();
}
