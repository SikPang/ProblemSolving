using System;

public class Solution
{
    long[] sum = new long[2];
    int[] pointer = new int[2];
    bool[] isChanged = new bool[2];
    int[] queue1;
    int[] queue2;
    int count = 0;

    public int solution(int[] queue1, int[] queue2)
    {
        this.queue1 = queue1;
        this.queue2 = queue2;

        for (int i = 0; i < queue1.Length; ++i)
        {
            sum[0] += queue1[i];
            sum[1] += queue2[i];
        }

        if (sum[0] == sum[1]) return 0;
        if ((sum[0] + sum[1]) % 2 != 0) return -1;

        while (sum[0] != sum[1])
        {
            if (count > queue1.Length * 3) return -1;

            if (sum[0] > sum[1])
                MoveTo2();
            else
                MoveTo1();
        }

        return count;
    }

    void MoveTo1()
    {
        if (!isChanged[1])
        {
            sum[0] += queue2[pointer[1]];
            sum[1] -= queue2[pointer[1]];
        }
        else
        {
            sum[0] += queue1[pointer[1]];
            sum[1] -= queue1[pointer[1]];
        }

        ++pointer[1];
        ++count;

        if (pointer[1] == queue2.Length)
        {
            pointer[1] = 0;

            if (isChanged[1]) isChanged[1] = false;
            else isChanged[1] = true;
        }
    }

    void MoveTo2()
    {
        if (!isChanged[0])
        {
            sum[0] -= queue1[pointer[0]];
            sum[1] += queue1[pointer[0]];
        }
        else
        {
            sum[0] -= queue2[pointer[0]];
            sum[1] += queue2[pointer[0]];
        }

        ++pointer[0];
        ++count;

        if (pointer[0] == queue1.Length)
        {
            pointer[0] = 0;

            if (isChanged[0]) isChanged[0] = false;
            else isChanged[0] = true;
        }
    }
}