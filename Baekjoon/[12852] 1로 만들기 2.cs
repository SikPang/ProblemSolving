using System.Text;

namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            int num = int.Parse(Console.ReadLine());
            int[] dp = new int[num + 1];
            int[] path = new int[num + 1];
            dp[1] = 0;      // 1일때 최소 횟수 0
            path[1] = 0;    // 1에서 0으로 가는게 최적의 방법

            for (int i = 2; i < num + 1; i++)
            {
                if (i % 3 == 0)
                {
                    if (i % 2 == 0)     // 3으로도 나누어지고, 2로도 나누어질 때
                    {
                        dp[i] = Math.Min(dp[i - 1] + 1, Math.Min(dp[i / 3] + 1, dp[i / 2] + 1));
                        if (dp[i] == dp[i - 1] + 1)
                            path[i] = i - 1;
                        else if (dp[i] == dp[i/3] + 1)
                            path[i] = i/3;
                        else if (dp[i] == dp[i/2] + 1)
                            path[i] = i/2;
                    }
                    else                // 3으로만 나누어질 때
                    {
                        dp[i] = Math.Min(dp[i / 3] + 1, dp[i - 1] + 1);
                        if (dp[i] == dp[i - 1] + 1)
                            path[i] = i - 1;
                        else if (dp[i] == dp[i / 3] + 1)
                            path[i] = i / 3;
                    }
                }
                else if (i % 2 == 0)    // 2로만 나누어질 때
                {
                    dp[i] = Math.Min(dp[i / 2] + 1, dp[i - 1] + 1);
                    if (dp[i] == dp[i - 1] + 1)
                        path[i] = i - 1;
                    else if (dp[i] == dp[i / 2] + 1)
                        path[i] = i / 2;
                }
                else                    // 3으로도 나누어지지 않고, 2로도 나누어지지 않을 때
                {
                    dp[i] = dp[i - 1] + 1;
                    path[i] = i - 1;
                }
            }

            sb.Append(dp[num]);
            sb.AppendLine();
            sb.Append(num + " ");
            int a = num;
            while (true)
            {
                if (a == 1) break;
                sb.Append(path[a] + " ");
                a = path[a];
            }

            Console.Write(sb.ToString());
        }
    }
}