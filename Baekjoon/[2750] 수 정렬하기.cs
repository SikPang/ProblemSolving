using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StringBuilder sb = new StringBuilder();
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int input = int.Parse(sr.ReadLine());
        int[] arr = new int[input];

        for(int i = 0; i < input; i++)
            arr[i] = int.Parse(sr.ReadLine());

        for(int i=0; i < arr.Length; i++)
        {
            for(int j=0; j < arr.Length-1-i; j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < input; i++)
        {
            sb.Append(arr[i]);
            sb.AppendLine();
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}