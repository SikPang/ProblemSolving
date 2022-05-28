namespace Program
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int[]> que = new Queue<int[]>();
            int[,] direction = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            int[] RGB = new int[3];
            int[] answer = new int[2];
            int num = int.Parse(Console.ReadLine());
            string[] map = new string[num];
            bool[,] isVisited = new bool[num, num];

            for (int i = 0; i < num; i++)
            {
                map[i] = Console.ReadLine();
            }

            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (!isVisited[i, j])
                    {
                        switch (map[i][j])
                        {
                            case 'R':
                                que.Enqueue(new int[] { i, j, 'R' });
                                RGB[0]++;
                                break;
                            case 'G':
                                que.Enqueue(new int[] { i, j, 'G' });
                                RGB[1]++;
                                break;
                            case 'B':
                                que.Enqueue(new int[] { i, j, 'B' });
                                RGB[2]++;
                                break;
                        }
                        isVisited[i, j] = true;

                        while (que.Count > 0)
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                if (que.Peek()[0] + direction[k, 0] >= 0 && que.Peek()[0] + direction[k, 0] < map.Length
                                    && que.Peek()[1] + direction[k, 1] >= 0 && que.Peek()[1] + direction[k, 1] < map[0].Length
                                    && !isVisited[que.Peek()[0] + direction[k, 0], que.Peek()[1] + direction[k, 1]] &&
                                    map[que.Peek()[0] + direction[k, 0]][que.Peek()[1] + direction[k, 1]] == que.Peek()[2])
                                {
                                    que.Enqueue(new int[] { que.Peek()[0] + direction[k, 0], que.Peek()[1] + direction[k, 1], que.Peek()[2] });
                                    isVisited[que.Peek()[0] + direction[k, 0], que.Peek()[1] + direction[k, 1]] = true;
                                }
                            }
                            que.Dequeue();
                        }
                    }
                }
            }
            answer[0] = RGB[0] + RGB[1] + RGB[2];

            isVisited = new bool[num, num];
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (!isVisited[i, j])
                    {
                        switch (map[i][j])
                        {
                            case 'R':
                            case 'G':
                                que.Enqueue(new int[] { i, j });
                                answer[1]++;
                                break;
                        }
                        isVisited[i, j] = true;

                        while (que.Count > 0)
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                if (que.Peek()[0] + direction[k, 0] >= 0 && que.Peek()[0] + direction[k, 0] < map.Length
                                    && que.Peek()[1] + direction[k, 1] >= 0 && que.Peek()[1] + direction[k, 1] < map[0].Length
                                    && !isVisited[que.Peek()[0] + direction[k, 0], que.Peek()[1] + direction[k, 1]] &&
                                    (map[que.Peek()[0] + direction[k, 0]][que.Peek()[1] + direction[k, 1]] == 'R' || map[que.Peek()[0] + direction[k, 0]][que.Peek()[1] + direction[k, 1]] == 'G'))
                                {
                                    que.Enqueue(new int[] { que.Peek()[0] + direction[k, 0], que.Peek()[1] + direction[k, 1]});
                                    isVisited[que.Peek()[0] + direction[k, 0], que.Peek()[1] + direction[k, 1]] = true;
                                }
                            }
                            que.Dequeue();
                        }
                    }
                }
            }
            answer[1] += RGB[2];

            Console.Write(answer[0] + " " + answer[1]);
        }
    }
}