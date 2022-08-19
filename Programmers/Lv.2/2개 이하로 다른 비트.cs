using System;

class Solution
{
    public long[] solution(long[] numbers)
    {
        long[] answer = new long[numbers.Length];

        for (int i = 0; i < numbers.Length; i++)
        {
            if ((numbers[i] + 1) % 4 != 0)
                answer[i] = numbers[i] + 1;
            else
                answer[i] = numbers[i] + FindNumber(numbers[i] + 1);
        }
        return answer;
    }

    long FindNumber(long n)
    {
        int i = 0;
        long temp = 4;

        while (n % temp == 0)
        {
            i++;
            temp *= 2;
        }

        return (long)Math.Pow(2,i);
    }
}