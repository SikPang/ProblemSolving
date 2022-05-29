namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] map = new int[n, 3];
            int answer = int.MaxValue;

            for (int i = 0; i < n; i++)
            {
                int[] temp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j = 0; j < temp.Length; j++)
                    map[i, j] = temp[j];
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int min = int.MaxValue;
                    for (int k = 0; k < 3; k++)
                    {
                        if (k == j) continue;

                        min = Math.Min(map[i, j] + map[i - 1, k], min);
                    }
                    map[i, j] = min;
                }
            }

            for (int i = 0; i < 3; i++)
                answer = Math.Min(map[n-1, i], answer);

            Console.Write(answer);
        }
    }
}