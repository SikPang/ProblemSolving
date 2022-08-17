using System.Text;

class Test
{
    static Queue<int> que = new Queue<int>();
    static Stack<int> stack = new Stack<int>();
    static StringBuilder sb = new StringBuilder();
    static List<int>[] graph;
    static bool[] isVisited;
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        graph = new List<int>[input[0] + 1];

        for (int i = 0; i < graph.Length; i++)
            graph[i] = new List<int>(input[0] + 1);

        for (int i = 0; i < input[1]; i++)
        {
            int[] edge = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]);
        }

        for (int i = 0; i < graph.Length; i++)
            graph[i].Sort();

        DFS(input[0] + 1, input[2]);
        BFS(input[0] + 1, input[2]);

        sw.Close();
    }

    static void DFS(int size, int startNum)
    {
        isVisited = new bool[size];

        stack.Push(startNum);

        while (stack.Count > 0)
        {
            int temp = stack.Pop();

            if (isVisited[temp]) continue;

            isVisited[temp] = true;
            sb.Append(temp + " ");

            for (int j = graph[temp].Count - 1; j >= 0; j--)
            {
                if (!isVisited[graph[temp][j]])
                {
                    stack.Push(graph[temp][j]);
                }
            }
        }

        sb.AppendLine();
        sw.Write(sb.ToString());
        sb.Clear();
    }

    static void BFS(int size, int startNum)
    {
        isVisited = new bool[size];

        que.Enqueue(startNum);
        isVisited[startNum] = true;

        while (que.Count > 0)
        {
            int temp = que.Dequeue();
            sb.Append(temp + " ");

            for (int j = 0; j < graph[temp].Count; j++)
            {
                if (!isVisited[graph[temp][j]])
                {
                    que.Enqueue(graph[temp][j]);
                    isVisited[graph[temp][j]] = true;
                }
            }
        }

        sb.AppendLine();
        sw.Write(sb.ToString());
        sb.Clear();
    }
}