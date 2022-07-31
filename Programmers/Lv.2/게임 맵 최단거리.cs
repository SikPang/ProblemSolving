public class Solution
{
    public int solution(int[,] maps)
    {
        int answer = 0;
        Queue<int[]> que = new Queue<int[]>();
        bool[,] isVisited = new bool[maps.GetLength(0), maps.GetLength(1)];
        int[,] direction = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

        que.Enqueue(new int[] { 0, 0, 1 });
        isVisited[0, 0] = true;

        while (que.Count > 0)
        {
            int[] temp = que.Dequeue();

            for (int i = 0; i < direction.GetLength(0); i++)
            {
                int nextY = temp[0] + direction[i, 0];
                int nextX = temp[1] + direction[i, 1];
                int nextNum = temp[2] + 1;

                if (nextY > -1 && nextY < maps.GetLength(0) && nextX > -1 && nextX < maps.GetLength(1)
                    && maps[nextY, nextX] == 1 && !isVisited[nextY, nextX])
                {
                    if (nextY == maps.GetLength(0) - 1 && nextX == maps.GetLength(1) - 1)
                    {
                        answer = Math.Max(answer, nextNum);

                        return answer;
                    }
                    else
                    {
                        que.Enqueue(new int[] { nextY, nextX, nextNum });
                        isVisited[nextY, nextX] = true;
                        answer = Math.Max(answer, nextNum);
                    }
                }
            }
        }

        return -1;
    }
}