using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();

        sr.ReadLine();
        int[] target = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        sr.ReadLine();
        int[] num = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        Array.Sort(target);

        for(int i=0; i<num.Length; i++)
        {
            if (Array.BinarySearch(target, num[i]) >= 0 && Array.BinarySearch(target, num[i]) < num.Length)
                sb.Append("1" + " ");
            else
                sb.Append("0" + " ");
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}