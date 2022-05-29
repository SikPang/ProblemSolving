using System.Text;

namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            int n = int.Parse(Console.ReadLine());
            int[] num = new int[n];
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                num[i] = int.Parse(Console.ReadLine());
                if(num[i] > max)
                    max = num[i];
            }

            int[] dp = new int[max+1];
            dp[1] = 1;  // 1일때 1

            for(int i = 2; i < max+1; i++)
            {
                if(i-2 > 0)
                {
                    if (i - 3 > 0)
                    {
                        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
                    }
                    else
                    {
                        dp[i] = dp[i - 2] + dp[i - 1] + 1;
                    }
                }
                else
                {
                    dp[i] = dp[i - 1] + 1;
                }
            }

            for(int i = 0; i < n; i++)
            {
                sb.Append(dp[num[i]]);
                sb.AppendLine();
            }

            Console.Write(sb.ToString());
        }
    }
}