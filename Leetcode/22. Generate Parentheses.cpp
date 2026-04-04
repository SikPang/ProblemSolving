class Solution {
private:
    void recur(vector<string>& answer, string& buffer, int n, int left, int right){
        if (buffer.size() == n*2){
            answer.push_back(buffer);
            return;
        }

        if (left < n){
            buffer.push_back('(');
            recur(answer, buffer, n, left+1, right);
            buffer.pop_back();
        }

        if (right < left){
            buffer.push_back(')');
            recur(answer, buffer, n, left, right+1);
            buffer.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string buffer;
        
        buffer.reserve(n*2);
        recur(answer, buffer, n, 0, 0);
        return answer;
    }
};