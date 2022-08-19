class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        Queue<int> que = new Queue<int>();
        int n = Convert.ToInt32(sr.ReadLine());
        int m = Convert.ToInt32(sr.ReadLine());
        List<int>[] graph = new List<int>[n+1];
        bool[] isVisited = new bool[n+1];
        int answer = 0;

        for(int i=0; i<graph.Length; i++)
        {
            graph[i] = new List<int>();
        }

        for(int i=0; i<m; i++)
        {
            int[] edge = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]);
        }

        que.Enqueue(1);
        isVisited[1] = true;

        while (que.Count > 0)
        {
            int temp = que.Dequeue();

            for (int i = 0; i < graph[temp].Count; i++) {
                if (isVisited[graph[temp][i]]) continue;

                que.Enqueue(graph[temp][i]);
                isVisited[graph[temp][i]] = true;
                answer++;
            }
        }

        sw.Write(answer.ToString());
        sw.Close();
    }
}