class Solution {
public:
    string reverseVowels(string s) {
        string ret(s);
        stack<char> vowelStack;
        queue<int> vowelIdxQ;

        for (int i=0; i<s.size(); ++i){
            char cur = s[i];
            if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u'
                || cur == 'A' || cur == 'E' || cur == 'I' || cur == 'O' || cur == 'U'){
                vowelStack.push(cur);
                vowelIdxQ.push(i);
            }
        }

        while (!vowelStack.empty()){
            ret[vowelIdxQ.front()] = vowelStack.top();
            vowelStack.pop();
            vowelIdxQ.pop();
        }
        return ret;
    }
};