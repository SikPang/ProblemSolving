/*
    i + j + k = l
    i + j + k가 l인지 이분탐색

    (i+j) + k = l
    (i+j) = l - k
    l - k가 (i+j)인지 이분탐색
 */
using System.Text;

class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();
        List<int> list = new List<int>();
        int max = int.MinValue;

        int num = Convert.ToInt32(sr.ReadLine());
        int[] mainArr = new int[num];

        for (int i = 0; i < num; i++)
            mainArr[i] = Convert.ToInt32(sr.ReadLine());

        for (int i = 0; i < num; i++)
        {
            for (int j = i; j < num; j++)
                list.Add(mainArr[i] + mainArr[j]);
        }

        Array.Sort(mainArr);    // 뺄 때 음수가 나오지 않게 하기 위해 정렬

        list = list.Distinct().ToList();
        list.Sort();            // 이진 탐색을 위해 정렬

        for (int i = 0; i < num; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (list.BinarySearch(mainArr[j] - mainArr[i]) < 0 || list.BinarySearch(mainArr[j] - mainArr[i]) > list.Count) continue;
                max = Math.Max(max, mainArr[j]);
            }
        }

        sb.Append(max.ToString());

        sw.Write(sb.ToString());
        sw.Close();
    }
}