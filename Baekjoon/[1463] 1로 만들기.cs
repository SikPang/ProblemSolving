namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            int[] dp = new int[num+1];
            dp[1] = 0;  // 1일때 최소 횟수 0

            for (int i = 2; i < num+1; i++)
            {
                if (i % 3 == 0)
                {
                    if (i % 2 == 0)   // 3으로도 나누어지고, 2로도 나누어질 때
                    {
                        dp[i] = Math.Min(dp[i - 1] + 1, Math.Min(dp[i / 3] + 1, dp[i / 2] + 1));
                    }
                    else                    // 3으로만 나누어질 때
                    {
                        dp[i] = Math.Min(dp[i / 3] + 1, dp[i - 1] + 1);
                    }
                }
                else if (i % 2 == 0)  // 2로만 나누어질 때
                {
                    dp[i] = Math.Min(dp[i / 2] + 1, dp[i - 1] + 1);
                }
                else                        // 3으로도 나누어지지 않고, 2로도 나누어지지 않을 때
                {
                    dp[i] = dp[i - 1] + 1;
                }
            }

            Console.Write(dp[num]);
        }
    }
}