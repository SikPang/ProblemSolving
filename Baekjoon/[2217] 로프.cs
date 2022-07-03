using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        int max = 0;
        int cnt = 1;

        int num = Convert.ToInt32(sr.ReadLine());
        int[] ropes = new int[num];

        for (int i = 0; i < num; i++)
            ropes[i] = Convert.ToInt32(sr.ReadLine());

        Array.Sort(ropes);

        for (int i = ropes.Length - 1; i >= 0; i--)
        {
            if (max < ropes[i] * cnt)
            {
                max = ropes[i] * cnt;
            }
            cnt++;
        }

        sw.Write(max.ToString());
        sw.Close();
    }
}