using System.Text;

class Test
{
    static List<int>[] tree;
    static bool[] isVisited;
    static int[] childNum;

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        StringBuilder sb = new StringBuilder();

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        tree = new List<int>[input[0]+1];
        for (int i = 0; i < input[0]+1; ++i)
            tree[i] = new List<int>();

        isVisited = new bool[tree.Length + 1];
        childNum = new int[tree.Length + 1];

        for (int i = 0; i < input[0] - 1; ++i)
        {
            int[] edges = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            tree[edges[0]].Add(edges[1]);
            tree[edges[1]].Add(edges[0]);
        }

        CountChild(input[1]);

        for (int i = 0; i < input[2]; ++i)
        {
            int num = Convert.ToInt32(sr.ReadLine());

            sb.AppendLine(childNum[num].ToString());
        }

        sw.Write(sb.ToString());
        sw.Close();
    }

    static int CountChild(int cur)
    {
        int cnt = 1;

        for(int i=0; i < tree[cur].Count; ++i)
        {
            if (isVisited[tree[cur][i]]) continue;

            isVisited[cur] = true;
            cnt += CountChild(tree[cur][i]);
        }

        childNum[cur] = cnt;
        return cnt;
    }
}