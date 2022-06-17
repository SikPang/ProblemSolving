using System;
using System.Collections;
using System.IO;
using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Stack stack;
        bool isBreaked;

        int num = int.Parse(sr.ReadLine());

        for (int i = 0; i < num; i++)
        {
            string input = sr.ReadLine();
            stack = new Stack();
            isBreaked = false;

            for (int j = 0; j < input.Length; j++)
            {
                if (isBreaked) break;

                if (stack.Count == 0)
                {
                    if (input[j] == ')')
                    {
                        isBreaked = true;
                        break;
                    }
                    else
                        stack.Push(input[j]);
                }
                else
                {
                    if (input[j] == ')')
                        stack.Pop();
                    else
                        stack.Push(input[j]);
                }
            }

            if (isBreaked || stack.Count != 0)
                sb.Append("NO");
            else
                sb.Append("YES");
            sb.AppendLine();
        }
        sw.Write(sb.ToString());
        sw.Close();
    }
}