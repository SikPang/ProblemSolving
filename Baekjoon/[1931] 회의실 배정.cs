namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            int cnt = 0;
            int input = int.Parse(Console.ReadLine());
            uint[] start = new uint[input];
            uint[] end = new uint[input];

            for (int i = 0; i < input; i++)
            {
                uint[] temp = Array.ConvertAll(Console.ReadLine().Split(), uint.Parse);
                start[i] = temp[0];
                end[i] = temp[1];
            }

            Array.Sort(end, start);

            uint time = 0;
            for (int i = 0; i < input; i++)
            {
                if (start[i] < time) continue;
                if (i < input - 1)
                {
                    if (end[i] == end[i + 1] && start[i] > start[i + 1])
                    {
                        uint[] temp = { start[i], end[i] };
                        start[i] = start[i + 1];
                        end[i] = end[i + 1];
                        start[i + 1] = temp[0];
                        end[i + 1] = temp[1];
                    }
                }
                cnt++;
                time = end[i];
            }
            Console.Write(cnt);
        }
    }
}