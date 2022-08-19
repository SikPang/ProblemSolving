class Test
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        int[] input = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
        List<int>[] graph = new List<int>[input[0] + 1];
        Queue<int> que = new Queue<int>();
        bool[] isVisited = new bool[input[0] + 1];
        int answer = 0;

        for (int i = 0; i < graph.Length; i++)
            graph[i] = new List<int>(input[0] + 1);

        for (int i = 0; i < input[1]; i++)
        {
            int[] edge = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);

            graph[edge[0]].Add(edge[1]);
            graph[edge[1]].Add(edge[0]);
        }

        for (int i = 1; i < isVisited.Length; i++)
        {
            if (isVisited[i]) continue;

            que.Enqueue(i);
            isVisited[i] = true;

            while (que.Count > 0)
            {
                int temp = que.Dequeue();

                for (int j = 0; j < graph[temp].Count; j++)
                {
                    if (!isVisited[graph[temp][j]])
                    {
                        que.Enqueue(graph[temp][j]);
                        isVisited[graph[temp][j]] = true;
                    }
                }
            }

            answer++;
        }

        sw.Write(answer.ToString());
        sw.Close();
    }
}