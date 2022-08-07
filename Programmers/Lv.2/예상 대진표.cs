using System;

public class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;

        while (a != b)
        {
            a = (int)Math.Ceiling(a / 2f);
            b = (int)Math.Ceiling(b / 2f);

            answer++;
        }

        return answer;
    }
}