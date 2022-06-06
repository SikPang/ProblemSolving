using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StringBuilder sb = new StringBuilder();
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        int[] answer = new int[input[0] + input[1]];

        int[] arr1 = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        int[] arr2 = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        int i = 0;
        int j = 0;
        for(int k=0; k<answer.Length; k++)
        {
            if (i>=arr1.Length || (j<arr2.Length && arr1[i] >= arr2[j]))
            {
                answer[k] = arr2[j];
                j++;
            }
            else if (j >= arr2.Length || (i < arr1.Length && arr1[i] <= arr2[j]))
            {
                answer[k] = arr1[i];
                i++;
            }
            sb.Append(answer[k] + " ");
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}