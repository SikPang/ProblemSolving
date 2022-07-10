class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int num = Convert.ToInt32(sr.ReadLine());
        long[] dp = new long[num+1];

        dp[1] = 1;

        for(int i = 2; i < num+1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        sw.Write(dp[num]);
        sw.Close();
    }
}