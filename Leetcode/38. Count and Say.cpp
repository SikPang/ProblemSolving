class Solution {
public:
    string countAndSay(int n) {
        string dp[n+1];
        dp[1] = "1";

        for (int i=2; i<=n; ++i){
            string prev = dp[i-1];
            string cur;

            for (int j=0; j<prev.size(); ++j){
                char num = prev[j];
                int k = j + 1;
                for (; k<prev.size(); ++k){
                    if (num != prev[k]) break;
                }
                int count = k - j;
                cur += count + '0';
                cur += num;
                j += count - 1;
            }
            cout << endl;
            dp[i] = cur;
        }
        return dp[n];
    }
};