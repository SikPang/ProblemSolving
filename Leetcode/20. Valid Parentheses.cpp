class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for (int i=0; i<s.size(); ++i){
            char cur = s[i];
            if (cur == '(' || cur == '{' || cur == '[' ){
                myStack.push(cur);
            } else{
                if (myStack.size() == 0) return false;
                char top = myStack.top();
                myStack.pop();

                if (cur == ')' && top != '(') return false;
                if (cur == '}' && top != '{') return false;
                if (cur == ']' && top != '[') return false;
            }
        }
        return myStack.size() == 0;
    }
};