class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        Queue<int[]> que = new Queue<int[]>();
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

        que.Enqueue(new int[] {1, 0});
        isVisited[1] = true;

        while (que.Count > 0)
        {
            int[] temp = que.Dequeue();

            if (temp[1] > 2) break;

            answer++;

            for (int i = 0; i < graph[temp[0]].Count; i++) {
                if (isVisited[graph[temp[0]][i]]) continue;

                que.Enqueue(new int[] { graph[temp[0]][i], temp[1] + 1 });
                isVisited[graph[temp[0]][i]] = true;
            }
        }

        if (answer != 0) answer--;

        sw.Write(answer.ToString());
        sw.Close();
    }
}