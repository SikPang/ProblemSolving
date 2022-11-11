#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int answer = 0;
stack<double> st;
vector<int> convertingNum;

void Calculate(char ch)
{
    double temp1 = st.top();
    st.pop();
    double temp2 = st.top();
    st.pop();

    switch (ch)
    {
    case '+':
        temp2 += temp1;
        break;
    case '-':
        temp2 -= temp1;
        break;
    case '*':
        temp2 *= temp1;
        break;
    case '/':
        temp2 /= temp1;
        break;
    }

    st.push(temp2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string str;

    cin >> n >> str;

    for (int i = 0; i < n; ++i)
    {
        int input;

        cin >> input;
        convertingNum.push_back(input);
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
            st.push(convertingNum[str[i] - 'A']);
        else
            Calculate(str[i]);
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
}