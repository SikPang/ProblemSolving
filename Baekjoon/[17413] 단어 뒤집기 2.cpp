#include <stack>
#include <iostream>
using namespace std;

char str[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> stack;
    bool isTagging = false;
    int i = 0;

    cin.getline(str, sizeof(str));

    while (str[i] != '\0')
    {
        if (str[i] == '<')
            isTagging = true;
        else if (str[i] == '>')
            isTagging = false;

        if (isTagging || str[i] == ' ')
        {
            while (!stack.empty())
            {
                cout << stack.top();
                stack.pop();
            }
            cout << str[i];
        }
        else
        {
            if (str[i] == '>')
                cout << str[i];
            else
                stack.push(str[i]);
        }
        ++i;
    }
    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}