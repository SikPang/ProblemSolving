class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string answer;
        char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        unsigned int target = num;

        while (target > 0){
            answer.push_back(hex[target % 16]);
            target /= 16;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};