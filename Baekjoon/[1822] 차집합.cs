using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        List<int> list = new List<int>();
        int cnt = 0;

        sr.ReadLine();
        int[] num = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        int[] target = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        Array.Sort(target);

        for(int i=0; i < num.Length; i++)
        {
            if(Array.BinarySearch(target, num[i])<0 || Array.BinarySearch(target, num[i]) >= target.Length)
            {
                cnt++;
                list.Add(num[i]);
            }
        }

        list.Sort();

        if (cnt == 0)
            sb.Append("0");
        else
        {
            sb.AppendLine(cnt.ToString());
            for (int i = 0; i < list.Count; i++)
                sb.Append(list[i] + " ");
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}