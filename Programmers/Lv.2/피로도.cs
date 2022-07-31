using System;

public class Solution
{
    int[,] dungeons;
    bool[] isVisited;
    int tiredness;
    int answer = 0;

    public int solution(int k, int[,] dungeons)
    {
        this.tiredness = k;
        this.dungeons = dungeons;
        isVisited = new bool[dungeons.GetLength(0)];

        VisitDungeons(0);

        return answer;
    }

    void VisitDungeons(int depth)
    {
        if (depth == dungeons.GetLength(0))
            return;

        for(int i=0; i<dungeons.GetLength(0); i++)
        {
            if (isVisited[i] || tiredness < dungeons[i,0]) continue;

            isVisited[i] = true;
            tiredness -= dungeons[i,1];

            answer = Math.Max(depth+1, answer);
            VisitDungeons(depth + 1);

            isVisited[i] = false;
            tiredness += dungeons[i, 1];
        }
    }
}