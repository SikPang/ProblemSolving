using System;
using System.Collections.Generic;

public class Solution
{
    string[,] places;
    int[,] direction = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    const int ManhattanDistance = 2;

    public int[] solution(string[,] places)
    {
        this.places = places;
        int[] answer = new int[places.GetLength(0)];

        for (int i = 0; i < answer.Length; i++)
            if (SocialDistancing(i)) answer[i] = 1;

        return answer;
    }

    bool SocialDistancing(int index)
    {
        Queue<int[]> que = new Queue<int[]>();
        bool[,] isVisited;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (places[index, i][j] == 'P')
                {
                    que.Enqueue(new int[] { i, j, 0 });
                    isVisited = new bool[places.GetLength(0), places.GetLength(1)];
                    isVisited[i, j] = true;

                    while (que.Count > 0)
                    {
                        int[] temp = que.Dequeue();

                        for (int k = 0; k < direction.GetLength(0); k++)
                        {
                            int nextX = temp[0] + direction[k, 0];
                            int nextY = temp[1] + direction[k, 1];

                            if (temp[2] < ManhattanDistance && nextX < 5 && nextX > -1 && nextY < 5 && nextY > -1 && !isVisited[nextX, nextY])
                            {
                                if (places[index, nextX][nextY] == 'P') return false;

                                if (places[index, nextX][nextY] != 'X')
                                {
                                    que.Enqueue(new int[] { nextX, nextY, temp[2] + 1 });
                                    isVisited[nextX, nextY] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
}