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

        for (int i = 0; i < num.Length; i++)
        {
            int start = 0;
            int end = target.Length;
            int leftIndex = 0;
            int rightIndex = 0;

            while (start < end)
            {
                int mid = (start + end) / 2;

                if (target[mid] < num[i])       // 찾으려는 수가 더 크다면
                    start = mid + 1;
                else                            // 찾으려는 수가 더 작다면
                    end = mid;
            }
            leftIndex = start;

            start = 0;
            end = target.Length;
            while (start < end)
            {
                int mid = (start + end) / 2;

                if (target[mid] <= num[i])       // 찾으려는 수가 더 크다면
                    start = mid + 1;
                else                            // 찾으려는 수가 더 작다면
                    end = mid;
            }
            rightIndex = start;

            sb.Append((rightIndex - leftIndex).ToString() + " ");
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}