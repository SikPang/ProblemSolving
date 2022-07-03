using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        int sum = 0;
        int cnt = 0;

        sr.ReadLine();

        int[] a = Array.ConvertAll(sr.ReadLine().Split(), Convert.ToInt32);
        int[] b = Array.ConvertAll(sr.ReadLine().Split(), Convert.ToInt32);

        Array.Sort(a);
        Array.Sort(b);

        for(int i= a.Length-1; i>=0; i--)
        {
            sum += a[i] * b[cnt];
            cnt++;
        }
        
        sw.Write(sum.ToString());
        sw.Close();
    }
}