using System;
using System.IO;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        int[,] rooms = new int[2,6];
        int answer = 0;

        int[] num = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        for(int i=0; i<num[0]; i++)
        {
            int[] student = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            rooms[student[0], student[1] - 1]++;
        }

        for(int i=0; i<rooms.GetLength(0); i++)
        {
            for(int j=0; j<rooms.GetLength(1); j++)
            {
                float temp = rooms[i, j] / (float)num[1];

                if (temp % 1 == 0)
                    answer += (int)temp;
                else
                    answer += (int)temp + 1;
            }
        }

        sw.WriteLine(answer.ToString());
        sw.Close();
    }
}