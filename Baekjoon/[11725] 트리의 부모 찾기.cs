using System.Text;

class Test
{
    static List<int>[] map;
    static int[] parent;

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();

        int n = Convert.ToInt32(sr.ReadLine());

        map = new List<int>[n + 1];
        for (int i = 0; i < map.Length; i++)
            map[i] = new List<int>();

        parent = new int[n + 1];

        for (int i = 0; i < n - 1; ++i)
        {
            int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            map[input[0]].Add(input[1]);
            map[input[1]].Add(input[0]);
        }

        FindParent(1);

        for (int i = 2; i < parent.Length; i++)
            sb.AppendLine(parent[i].ToString());

        sw.Write(sb.ToString());
        sw.Close();
    }

    static void FindParent(int cur)
    {
        for(int i=0; i < map[cur].Count; i++)
        {
            if (parent[map[cur][i]] != 0) continue;
            parent[map[cur][i]] = cur;
            FindParent(map[cur][i]);
        }
    }
}