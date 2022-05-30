namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[] num = new int[input[0]];
            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < input[0]; i++)
                num[i] = int.Parse(Console.ReadLine());

            int j = num.Length - 1;
            while (sum < input[1] || j >= 0)
            {
                if (num[j] + sum > input[1])
                {
                    j--;
                    continue;
                }
                sum += num[j];
                cnt++;
            }
            Console.Write(cnt);
        }
    }
}