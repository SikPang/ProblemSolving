using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Dictionary<string, int> dictStr = new Dictionary<string, int>();
        Dictionary<int, string> dictInt = new Dictionary<int, string>();

        int[] num = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        for(int i=0; i<num[0]; i++)
        {
            string name = sr.ReadLine();

            dictStr.Add(name, i+1);
            dictInt.Add(i + 1, name);
        }

        for(int i=0; i<num[1]; i++)
        {
            bool isTrue = false;
            int answerInt;
            string answerStr;

            string input = sr.ReadLine();

            isTrue = dictStr.TryGetValue(input, out answerInt);

            if (isTrue)
                sb.AppendLine(answerInt.ToString());
            else
            {
                dictInt.TryGetValue(Convert.ToInt32(input), out answerStr);
                sb.AppendLine(answerStr);
            }
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}