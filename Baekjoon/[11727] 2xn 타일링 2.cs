using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();

        int n = int.Parse(sr.ReadLine());
        int[] dp = new int[n + 1];
        dp[1] = 1;

        if (n >= 2)
            dp[2] = 3;

        for (int i = 3; i < n + 1; i++)
            dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;

        sb.Append(dp[n]);

        sw.Write(sb.ToString());
        sw.Close();
    }
}