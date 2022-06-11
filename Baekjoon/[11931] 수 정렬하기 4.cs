using System.Text;

class Test
{
    static int[] arr;
    static int[] temp;

    static void Main(string[] args)
    {
        StringBuilder sb = new StringBuilder();
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int input = int.Parse(sr.ReadLine());
        arr = new int[input];
        temp = new int[input];

        for (int i = 0; i < input; i++)
            arr[i] = int.Parse(sr.ReadLine());

        if(input != 1)
            MergeSort(0, arr.Length);

        for (int i = input-1; i >= 0; i--)
        {
            sb.Append(arr[i]);
            sb.AppendLine();
        }

        sw.Write(sb.ToString());
        sw.Close();
    }

    static void MergeSort(int start, int end)
    {
        if (end == start+1)
            return;

        MergeSort(start, (start+end) / 2);
        MergeSort((start + end) / 2, end);

        Merge(start, end);
    }

    static void Merge(int start, int end)
    {
        int mid = (start + end) / 2;

        int i = start;
        int j = mid;
        for (int k = start; k < end; k++)
        {
            if (i >= mid || (j < end && arr[i] >= arr[j]))
            {
                temp[k] = arr[j];
                j++;
            }
            else if (j >= end || (i < mid && arr[i] <= arr[j]))
            {
                temp[k] = arr[i];
                i++;
            }
        }
        for(int k=start; k<end; k++)
            arr[k] = temp[k];
    }
}