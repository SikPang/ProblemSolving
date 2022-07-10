using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        
        string input = sr.ReadLine();

        char[] num = input.ToCharArray();

        Array.Sort(num);

        for(int i=num.Length-1; i>=0; i--) 
            sb.Append(num[i]);

        sw.Write(sb.ToString());
        sw.Close();
    }
}