#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
    stack<char> stack;

    for(int i=0; i<s.size(); ++i)
    {
        if (!stack.empty() && stack.top() == s[i])
            stack.pop();
        else
            stack.push(s[i]);
    }
    
    if (stack.empty())
        return 1;
    else
        return 0;
}