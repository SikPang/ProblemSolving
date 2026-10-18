class Solution {
public:
    string removeDuplicates(string s) {
        string answer;

        for (int i=0; i<s.size(); ++i){
            if (!answer.empty() && answer.back() == s[i]){
                answer.pop_back();
            } else {
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};