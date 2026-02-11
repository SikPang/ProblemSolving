class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        string answer;
        bool isNegative = num < 0;

        while (num != 0){
            answer.push_back(abs(num % 7) + '0');
            num /= 7;
        }

        if (isNegative) {
            answer.push_back('-');
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};