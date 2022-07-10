class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        Queue<int[]> que = new Queue<int[]>();
        // 상 하 좌 우 앞 뒤 (높이, 상하, 좌우)
        int[,] direction = { { 0, -1, 0 }, { 0, 1, 0 }, { 0, 0, -1 }, { 0, 0, 1 }, { -1, 0, 0 }, { 1, 0, 0 } };
        int answer = 0;
        bool isBreaked = false;

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        int[,,] box = new int[input[2], input[1], input[0]];

        for (int i = 0; i < input[2]; i++)
        {
            for (int j = 0; j < input[1]; j++)
            {
                int[] temp = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

                for (int k = 0; k < input[0]; k++)
                {
                    box[i, j, k] = temp[k];

                    if (temp[k] == 1)
                        que.Enqueue(new int[] { i, j, k, 0 });
                }
            }
        }

        while (que.Count > 0)
        {
            int[] peek = new int[] { que.Peek()[0], que.Peek()[1], que.Peek()[2], que.Peek()[3] };
            que.Dequeue();

            for (int i = 0; i < direction.GetLength(0); i++)
            {
                int[] next = { peek[0] + direction[i, 0], peek[1] + direction[i, 1], peek[2] + direction[i, 2], peek[3] + 1 };
                if (next[0] < box.GetLength(0) && next[0] >= 0 && next[1] < box.GetLength(1) && next[1] >= 0 &&
                   next[2] < box.GetLength(2) && next[2] >= 0 && box[next[0], next[1], next[2]] == 0)
                {
                    answer = Math.Max(answer, next[3]);
                    que.Enqueue(new int[] { next[0], next[1], next[2], next[3] });
                    box[next[0], next[1], next[2]] = 1;
                }
            }
        }

        for(int i=0; i<box.GetLength(0); i++)
        {
            for (int j = 0; j < box.GetLength(1); j++)
            {
                for (int k = 0; k < box.GetLength(2); k++)
                {
                    if(box[i,j,k] == 0)
                    {
                        isBreaked = true;
                        break;
                    }
                }
                if (isBreaked) break;
            }
            if (isBreaked) break;
        }

        if (isBreaked)
            sw.Write("-1");
        else
            sw.Write(answer.ToString());

        sw.Close();
    }
}