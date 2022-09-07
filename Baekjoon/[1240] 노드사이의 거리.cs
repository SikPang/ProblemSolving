using System.Text;

class Test
{
    static List<int[]>[] tree;
    static int sum;
    static StringBuilder sb;
    static bool isBreaked;
    static bool[] isVisited;

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        sb = new StringBuilder();

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

        tree = new List<int[]>[input[0]+1];
        for (int i = 0; i < input[0]+1; ++i)
            tree[i] = new List<int[]>();

        for (int i = 0; i < input[0] - 1; ++i)
        {
            int[] edges = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            tree[edges[0]].Add(new int[] { edges[1], edges[2] });
            tree[edges[1]].Add(new int[] { edges[0], edges[2] });
        }

        for (int i = 0; i < input[1]; ++i)
        {
            int[] edges = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
            isVisited = new bool[tree.Length + 1];
            isBreaked = false;

            DFS(edges[0], edges[1]);
        }

        sw.Write(sb.ToString());
        sw.Close();
    }

    static void DFS(int cur, int dest)
    {
        if(cur == dest)
        {
            sb.AppendLine(sum.ToString());
            isBreaked = true;

            return;
        }

        for(int i=0; i < tree[cur].Count; ++i)
        {
            if (isBreaked) return;
            if (isVisited[cur]) continue;

            sum += tree[cur][i][1];
            isVisited[cur] = true;

            DFS(tree[cur][i][0], dest);

            sum -= tree[cur][i][1];
            isVisited[cur] = false;
        }
    }
}