using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Dictionary<string, int> dict = new Dictionary<string, int>();
        int cnt = 0;

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        for(int i=0; i < input[1]; i++)
        {
            string num = sr.ReadLine();
            
            bool check = dict.TryAdd(num, i);
            if (!check)
            {
                dict.Remove(num);
                dict.Add(num, i);
            }
        }

        dict = dict.OrderBy(x => x.Value).ToDictionary(x => x.Key, x => x.Value);

        foreach(string key in dict.Keys)
        {
            if (cnt == input[0]) break;

            sb.AppendLine(key);

            cnt++;
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}