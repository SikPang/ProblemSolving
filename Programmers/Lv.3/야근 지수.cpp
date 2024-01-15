#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> heap(works.begin(), works.end());
    long long answer = 0;
    
    for (int i=0; i<n; ++i)
    {
        int cur = heap.top();
        if (cur == 0) break;
        
        heap.pop();
        heap.push(cur-1);
    }
    
    while (!heap.empty())
    {
        answer += (long long)heap.top() * heap.top();
        heap.pop();
    }
    return answer;
}