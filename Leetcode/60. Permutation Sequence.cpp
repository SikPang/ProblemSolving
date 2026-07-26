class Solution {
private:
    void getPermutationRecur(string& str, string& buffer, vector<bool>& isUsed, int& cur, int target, int depth){
        if (depth == str.size()){
            if (cur == target) throw true;
            ++cur;
            return;
        }

        for (int i=0; i<str.size(); ++i){
            if (isUsed[i]) continue;
            buffer[depth] = str[i];
            isUsed[i] = true;

            getPermutationRecur(str, buffer, isUsed, cur, target, depth+1);

            isUsed[i] = false;
        }
    }

public:
    string getPermutation(int n, int k) {
        string str(n, ' ');
        string buffer(n, ' ');
        vector<bool> isUsed(n);
        int cur = 1;

        for (int i=0; i<n; ++i){
            str[i] = i+1+'0';
        }

        try{
            getPermutationRecur(str, buffer, isUsed, cur, k, 0);
        } catch (bool s){
            return buffer;
        }
        return buffer;
    }
};