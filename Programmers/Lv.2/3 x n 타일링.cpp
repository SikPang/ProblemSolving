#define MOD 1000000007

using namespace std;

int solution(int n) {
    long long dp[5001] = {};
    int base = 3;
    
    dp[2] = base;
    dp[4] = 11;
    for (int i=6; i<=n; i+=2)
    {
        dp[i] = (dp[i-2] * base + 2) % MOD;
        for (int j=i-4; j>=2; j-=2)
            dp[i] = (dp[i] + dp[j] * 2) % MOD;
    }
    return dp[n];
}