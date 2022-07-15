using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Dictionary<string, List<string>> dict;
        int answer;

        int testCase = Convert.ToInt32(sr.ReadLine());

        for (int i = 0; i < testCase; i++)
        {
            dict = new Dictionary<string, List<string>>();
            answer = 1;

            int num = Convert.ToInt32(sr.ReadLine());

            for (int j = 0; j < num; j++)
            {
                string[] input = sr.ReadLine().Split();

                bool check = dict.TryAdd(input[1], new List<string> { input[0] });
                if (!check)
                {
                    List<string> temp = dict[input[1]];
                    temp.Add(input[0]);
                    dict[input[1]] = temp;
                }
            }

            foreach (string key in dict.Keys)
                answer *= dict[key].Count + 1;

            sb.AppendLine((answer - 1).ToString());
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}