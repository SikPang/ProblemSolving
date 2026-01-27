class Solution {
public:
    string addStrings(string num1, string num2) {
        string answer;
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        
        answer.reserve(max(idx1+1, idx2+1));

        int over = 0;
        while (idx1 >= 0 || idx2 >= 0){
            int next1 = idx1 >=0 ? num1[idx1--] - '0' : 0;
            int next2 = idx2 >=0 ? num2[idx2--] - '0' : 0;
            int next3 = next1 + next2 + over;

            answer.push_back(next3 % 10 + '0');
            over = next3 / 10;
        }

        if (over != 0){
            answer.push_back(over + '0');
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};