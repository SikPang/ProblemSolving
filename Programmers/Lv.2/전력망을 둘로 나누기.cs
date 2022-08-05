using System;

public class Solution
{
    int[,] wires;
    bool[] isUsed;
    int max;

    public int solution(int n, int[,] wires)
    {
        this.wires = wires;
        isUsed = new bool[wires.GetLength(0)];

        int answer = int.MaxValue;

        for (int i = 0; i < wires.GetLength(0); i++)
        {
            max = 1;

            Find(i, wires[i, 1]);

            answer = Math.Min(answer, Math.Abs(n - max - max));
        }

        return answer;
    }

    void Find(int index, int nextNode)
    {
        for (int i = 0; i < wires.GetLength(0); i++)
        {
            if (index == i || isUsed[i]) continue;

            for (int j = 0; j < wires.GetLength(1); j++)
            {
                if (wires[i, j] == nextNode)
                {
                    isUsed[i] = true;
                    max++;

                    if (j == 0)
                        Find(index, wires[i, 1]);
                    else
                        Find(index, wires[i, 0]);

                    isUsed[i] = false;
                }
            }
        }
    }
}