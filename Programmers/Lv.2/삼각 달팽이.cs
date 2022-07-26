using System.Collections.Generic;

public class Solution
{
    public List<int> solution(int n)
    {
        List<int> answer = new List<int>();
        int[,] map = new int[n, n];
        int count = 1;
        int turn = 0;
        int deadLine = 0;

        while(deadLine < n)
        {
            for (int j = turn; j < map.GetLength(0); j++)
            {
                if (map[j, turn] != 0) continue;
                map[j, turn] = count++;
            }

            deadLine++;
            if (deadLine == n) break;

            for (int j = 0; j < map.GetLength(1) - turn; j++)
            {
                if (map[map.GetLength(1) - 1 - turn, j] != 0) continue;
                map[map.GetLength(1) - 1 - turn, j] = count++;
            }

            deadLine++;
            if (deadLine == n) break;

            for (int j = map.GetLength(0) - 1; j >= turn; j--)
            {
                if (map[j, j-turn] != 0) continue;
                map[j, j-turn] = count++;
            }

            deadLine++;
            if (deadLine == n) break;

            turn++;
        }

        for(int i=0; i<map.GetLength(0); i++)
        {
            for(int j=0; j < i+1; j++)
                answer.Add(map[i, j]);
        }

        return answer;
    }
}