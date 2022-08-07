using System;

class Solution
{
    int[,] road;
    int[] minCheck;
    bool[] isVisited;
    int townNum;
    int maxTime;
    int time;
    int answer;

    public int solution(int N, int[,] road, int K)
    {
        this.road = road;
        townNum = N;
        maxTime = K;
        time = K;
        answer = 1;

        minCheck = new int[N + 1];
        for (int i = 0; i < minCheck.GetLength(0); i++)
            minCheck[i] = int.MaxValue;

        isVisited = new bool[N + 1];
        isVisited[1] = true;

        FindWay(1);

        return answer;
    }

    void FindWay(int current)
    {
        for (int i = 0; i < road.GetLength(0); ++i)
        {
            if (road[i, 0] == current && !isVisited[road[i, 1]] && time >= road[i, 2] && minCheck[road[i, 1]] > maxTime - time + road[i, 2])
            {
                isVisited[road[i, 1]] = true;
                time -= road[i, 2];

                if (minCheck[road[i, 1]] == int.MaxValue)
                    answer++;

                minCheck[road[i, 1]] = maxTime - time;

                FindWay(road[i, 1]);

                isVisited[road[i, 1]] = false;
                time += road[i, 2];
            }
            else if (road[i, 1] == current && !isVisited[road[i, 0]] && time >= road[i, 2] && minCheck[road[i, 0]] > maxTime - time + road[i, 2])
            {
                isVisited[road[i, 0]] = true;
                time -= road[i, 2];

                if (minCheck[road[i, 0]] == int.MaxValue)
                    answer++;

                minCheck[road[i, 0]] = maxTime - time;

                FindWay(road[i, 0]);

                isVisited[road[i, 0]] = false;
                time += road[i, 2];
            }
        }
    }
}