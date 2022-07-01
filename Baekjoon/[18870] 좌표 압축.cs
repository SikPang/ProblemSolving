using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();

        sr.ReadLine();
        int[] mainArr = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        int[] compArr = new int[mainArr.Length];

        Array.Copy(mainArr, compArr, mainArr.Length);

        compArr = compArr.Distinct().ToArray();
        Array.Sort(compArr);

        for(int i=0; i<mainArr.Length; i++)
            sb.Append(Array.BinarySearch(compArr, mainArr[i]).ToString() + " ");

        sw.Write(sb.ToString());
        sw.Close();
    }
}