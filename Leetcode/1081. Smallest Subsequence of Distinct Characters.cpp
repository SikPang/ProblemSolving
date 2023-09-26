class Solution {
public:
	string smallestSubsequence(string s) {
		int counter['z'+1] = {};
		bool isUsed['z'+1] = {};
		for (int i=0; i<s.length(); ++i)
			++counter[s[i]];

		stack<char> stack;
		for (int i=0; i<s.length(); ++i)
		{
			--counter[s[i]];
			if (isUsed[s[i]]) continue;

			while (!stack.empty() && stack.top() > s[i] && counter[stack.top()] > 0)
			{
				isUsed[stack.top()] = false;
				stack.pop();
			}
			isUsed[s[i]] = true;
			stack.push(s[i]);
		}

		string answer;
		answer.resize(stack.size());
		for (int i=answer.size()-1; i>=0; --i)
		{
			answer[i] = stack.top();
			stack.pop();
		}
		return answer;
	}
};