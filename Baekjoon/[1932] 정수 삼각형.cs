using System;
using System.IO;
using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();

        int num = int.Parse(sr.ReadLine());
        int[,] input = new int[num + 10, num + 10];

        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                input[i, j] = -1;
            }
        }

        for (int i=0; i<num; i++)
        {
            int[] temp = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
            for (int j = 0; j < temp.Length; j++)
                input[i, j] = temp[j];
        }

        if (num == 1)
            sb.Append(input[0, 0]);
        else
        {
            for (int i = 1; i < num; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (j == 0)
                        input[i, j] += input[i - 1, j];
                    else if (j == i)
                        input[i, j] += input[i - 1, j - 1];
                    else
                    {
                        if (input[i - 1, j] > input[i - 1, j - 1])
                            input[i, j] += input[i - 1, j];
                        else
                            input[i, j] += input[i - 1, j - 1];
                    }
                }
            }

            int max = 0;

            for (int i = 0; i < num; i++)
            {
                if (input[num - 1, i] > max)
                    max = input[num - 1, i];
            }

            sb.Append(max);
        }

        sw.WriteLine(sb.ToString());
        sw.Close();
    }
}