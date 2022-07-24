public class Solution
{
    public int solution(string dirs)
    {
        bool[,] isVisited = new bool[21,21];    // (10.10)가 원점, 홀수가 경로, 짝수가 점
        int answer = 0;
        int[] current = { 10, 10 };
        int[] path = { 10, 10 };
        bool isMoved = false;

        for (int i=0; i<dirs.Length; i++)
        {
            Array.Copy(current, path, current.Length);
            isMoved = false;

            switch (dirs[i])
            {
                case 'U':
                    if (current[0] - 2 >= 0)
                    {
                        isMoved = true;
                        current[0] -= 2;
                        path[0]--;
                    }
                    break;
                case 'D':
                    if (current[0] + 2 < isVisited.GetLength(0))
                    {
                        isMoved = true;
                        current[0] += 2;
                        path[0]++;
                    }
                    break;
                case 'L':
                    if (current[1] - 2 >= 0)
                    {
                        isMoved = true;
                        current[1] -= 2;
                        path[1]--;
                    }
                    break;
                case 'R':
                    if (current[1] + 2 < isVisited.GetLength(1))
                    {
                        isMoved = true;
                        current[1] += 2;
                        path[1]++;
                    }
                    break;
            }

            if (isMoved)
            {
                if (isVisited[path[0], path[1]] == false)
                {
                    isVisited[path[0], path[1]] = true;
                    answer++;
                }
            }
        }

        return answer;
    }
}