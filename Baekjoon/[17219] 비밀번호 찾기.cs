using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Dictionary<string,string> dict = new Dictionary<string,string>();

        int[] num = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        for (int i = 0; i < num[0]; i++)
        {
            string[] input = sr.ReadLine().Split();

            dict.Add(input[0], input[1]);
        }

        for (int i = 0; i < num[1]; i++)
        {
            string input = sr.ReadLine();

            sb.AppendLine(dict[input]);
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}