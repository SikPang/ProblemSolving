namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] dp = new int[n+1];
            dp[1] = 1;

            if(n >= 2)
                dp[2] = 2;

            for(int i = 3; i < n+1; i++)
                dp[i] = (dp[i-2] + dp[i-1])%10007;

            Console.Write(dp[n]);
        }
    }
}