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
            int end = target.Length - 1;
            bool isExisted = false;

            while (start <= end)
            {
                int mid = (start + end) / 2;

                if(target[mid] == num[i])
                {
                    isExisted = true;
                    break;
                }
                else if(target[mid] < num[i])   // 찾으려는 수가 더 크다면
                    start = mid+1;
                else                            // 찾으려는 수가 더 작다면
                    end = mid-1;
            }

            if (isExisted)
                sb.AppendLine("1");
            else
                sb.AppendLine("0");
        }

        sw.Write(sb.ToString());
        sw.Close();
    }
}