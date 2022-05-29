using System.Text;

namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[] num = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[,] list = new int[input[1],2];
            int[] dp = new int[num.Length + 1];
            dp[1] = num[0];

            for(int i=0; i<input[1]; i++)
            {
                int[] temp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for(int j=0; j<2; j++)
                    list[i,j] = temp[j];
            }

            for (int i=2; i<num.Length+1; i++)
                dp[i] = dp[i-1] + num[i-1];

            for(int i=0; i<input[1]; i++)
            {
                sb.Append(dp[list[i, 1]] - dp[list[i, 0] - 1]);
                sb.AppendLine();
            }

            Console.Write(sb.ToString());
        }
    }
}