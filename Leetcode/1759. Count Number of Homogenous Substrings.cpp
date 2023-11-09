class Solution {
public:
    int countHomogenous(string s) {
        int startIdx = 0;
        char prev = s[0];
        int answer = 1;

        for (int i=1; i<s.length(); ++i)
        {
            if (s[i] != prev)
            {
                startIdx = i;
                prev = s[i];
            }
            answer = (answer + i-startIdx+1) % 1000000007;
        }
        return answer;
    }
};