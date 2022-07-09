using System.Collections.Generic;
using System.Text;
using System;
using System.IO;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Queue<int[]> que = new Queue<int[]>();
        // 상 하 좌 우 앞 뒤 (높이, 상하, 좌우)
        int[,] direction = { { 0, -1, 0 }, { 0, 1, 0 }, { 0, 0, -1 }, 
                            { 0, 0, 1 }, { -1, 0, 0 }, { 1, 0, 0 } };

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        int[,,] box = new int [input[2], input[1], input[0]];
        bool[,,] isVisited = new bool[input[2], input[1], input[0]];

        for (int i = 0; i < input[2]; i++)
        {
            for (int j = 0; j < input[1]; j++)
            {
                int[] temp = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

                for (int k = 0; k < input[0]; k++)
                {
                    box[i, j, k] = temp[k];
                    //sb.Append(box[i, j, k] + " ");

                    if (temp[k] == 1)
                    {
                        que.Enqueue(new int[] { i, j, k, 0 });
                        isVisited[i, j, k] = true;
                    }
                }
                //sb.AppendLine();
            }
            //sb.AppendLine();
        }

        while(que.Count > 0)
        {
            int[] peek = new int[] { que.Peek()[0], que.Peek()[1], que.Peek()[2], que.Peek()[3] };

            for(int i=0; i<direction.Length; i++)
            {
                if(peek[0]+direction[i,0] < box.GetLength(0) && peek[0] + direction[i, 0] >= 0 &&
                   peek[1] + direction[i, 1] < box.GetLength(1) && peek[1] + direction[i, 1] >= 0 &&
                   peek[2] + direction[i, 2] < box.GetLength(2) && peek[2] + direction[i, 2] >= 0 &&
                   !isVisited[peek[0]+ direction[i, 0], peek[1] + direction[i, 1], peek[2] + direction[i, 2]] &&
                   box[peek[0] + direction[i, 0], peek[1] + direction[i, 1], peek[2] + direction[i, 2]] == 0)
                {

                }
            }

            que.Dequeue();
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}