#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    answer.reserve(n);
    while (s > 0)
    {
        int div = s / n;
        if (div == 0) break;
        s -= div;
        answer.push_back(div);
        --n;
    }
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}