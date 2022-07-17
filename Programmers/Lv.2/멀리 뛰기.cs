public class Solution
{
    public int solution(int n)
    {
        int[] dp = new int[n+1];

        for(int i=1; i<3; i++)
        {
            dp[i] = i;
            if (n == i)
                return dp[i];
        }

        for (int i=3; i<n+1; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;

        return dp[n];
    }
}