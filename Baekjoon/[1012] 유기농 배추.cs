using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Queue<int[]> que = new Queue<int[]>();
        int answer;
        int[,] direction = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        int tc = int.Parse(sr.ReadLine());

        for (int q = 0; q < tc; q++)
        {
            sb.Clear();
            que.Clear();
            answer = 0;

            int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            int[,] map = new int[input[1], input[0]];
            bool[,] visited = new bool[input[1], input[0]];

            for (int i = 0; i < input[2]; i++)
            {
                int[] pos = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                map[pos[1], pos[0]] = 1;
            }

            for (int i = 0; i < map.GetLength(0); i++)
            {
                for (int j = 0; j < map.GetLength(1); j++)
                {
                    if (map[i, j] == 1 && !visited[i, j])
                    {
                        que.Enqueue(new int[] { i, j });
                        visited[i, j] = true;

                        while (que.Count != 0)
                        {
                            int y = que.Peek()[0];
                            int x = que.Peek()[1];
                            que.Dequeue();

                            for (int k = 0; k < direction.GetLength(0); k++)
                            {
                                if (y + direction[k, 0] < map.GetLength(0) && y + direction[k, 0] > -1 &&
                                    x + direction[k, 1] < map.GetLength(1) && x + direction[k, 1] > -1 &&
                                    map[y + direction[k, 0], x + direction[k, 1]] == 1 && !visited[y + direction[k, 0], x + direction[k, 1]])
                                {
                                    que.Enqueue(new int[] { y + direction[k, 0], x + direction[k, 1] });
                                    visited[y + direction[k, 0], x + direction[k, 1]] = true;
                                }
                            }
                        }
                        answer++;
                    }
                }
            }
            sb.Append(answer);
            sb.AppendLine();
            sw.Write(sb.ToString());
        }
        sw.Close();
    }
}