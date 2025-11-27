class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        for (int i=0; i<columnTitle.size(); ++i){
            int n = columnTitle[i] - 'A' + 1;
            answer = answer * 26 + n;
        }
        return answer;
    }
};