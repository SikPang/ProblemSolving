using System;
using System.Text;

public class Solution
{
    public string solution(string[] survey, int[] choices)
    {
        StringBuilder sb = new StringBuilder();
        int[] arr = new int[26];
        char[,] mbti = { { 'R', 'T' }, { 'C', 'F' }, { 'J', 'M' }, { 'A', 'N' } };

        for (int i = 0; i < survey.Length; ++i)
        {
            int score = choices[i] - 4;

            if (score < 0)  // 비동의
                arr[survey[i][0] - 65] += Math.Abs(score);
            else            // 동의
                arr[survey[i][1] - 65] += Math.Abs(score);
        }

        for (int i = 0; i < mbti.GetLength(0); ++i)
        {
            if (arr[mbti[i, 0] - 65] < arr[mbti[i, 1] - 65])
                sb.Append(mbti[i, 1]);
            else
                sb.Append(mbti[i, 0]);
        }

        return sb.ToString();
    }
}