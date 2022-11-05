#include <stack>
#include <string>
#include <vector>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<int> right;

    for (int i=1; i<food.size(); ++i)
    {
        int temp = food[i] / 2;

        if (food[i] / 2 == 0) continue;

        for (int j=0; j<temp; ++j)
        {
            answer += (i + '0');
            right.push(i);
        }
    }

    answer += '0';

    while (!right.empty())
    {
        answer += (right.top() + '0');
        right.pop();
    }

    return answer;
}