using System.Text;

class Test
{
    static StringBuilder sb = new StringBuilder();
    static List<int> list = new List<int>();
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
    static int max;
    static bool[] isUsed;
    static int[] input;

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());

        while (true)
        {
            input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            if (input[0] == 0) break;

            max = input[0];
            isUsed = new bool[input[0]];

            Lotto(0, 0);
            sb.AppendLine();
        }

        sw.Write(sb.ToString());
        sw.Close();
    }

    static void Lotto(int depth, int index)
    {
        if (depth == 6)
        {
            for (int i = 0; i < list.Count; i++)
            {
                sb.Append(list[i] + " ");
            }
            sb.AppendLine();

            if (sb.Length > 500)
            {
                sw.Write(sb.ToString());
                sb.Clear();
            }
            return;
        }

        for (int i = index; i < max; i++)
        {
            if (isUsed[i]) continue;

            isUsed[i] = true;
            list.Add(input[i + 1]);

            Lotto(depth + 1, i+1);

            isUsed[i] = false;
            list.RemoveAt(list.Count - 1);
        }
    }
}