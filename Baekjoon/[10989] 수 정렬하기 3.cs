using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StringBuilder sb = new StringBuilder();
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int input = int.Parse(sr.ReadLine());
        int[] arr = new int[10001];

        for (int i = 0; i < input; i++)
            arr[int.Parse(sr.ReadLine())]++;

        for (int i = 1; i< arr.Length; i++)
        {
            if (arr[i] == 0) continue;

            for (int j = 0; j < arr[i]; j++)
            {
                if(sb.Length > 500)
                {
                    sw.Write(sb.ToString());
                    sb.Clear();
                }
                sb.Append(i);
                sb.AppendLine();
            }
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}