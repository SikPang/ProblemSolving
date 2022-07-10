using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        Dictionary<string, bool> dic = new Dictionary<string, bool>();
        string[] remain;

        int num = Convert.ToInt32(sr.ReadLine());

        for(int i=0; i<num; i++)
        {
            string[] input = sr.ReadLine().Split();
            bool isTrue = false;
            
            isTrue = dic.TryAdd(input[0], true);
            
            if(!isTrue)
                dic.Remove(input[0]);
        }
        remain = new string[dic.Count];

        int cnt = 0;
        foreach(string key in dic.Keys)
        {
            remain[cnt] = key;

            cnt++;
        }

        Array.Sort(remain);

        for(int i=remain.Length-1; i>=0; i--)
        {
            sb.AppendLine(remain[i]);
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}