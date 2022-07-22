using System;
using System.Collections.Generic;

public class Solution
{
    public int[] solution(int n, string[] words)
    {
        Dictionary<string, bool> dict = new Dictionary<string, bool>();

        string prev = words[0];
        dict.Add(prev, true);

        for(int i=1; i < words.Length; i++)
        {
            if (prev[prev.Length - 1] != words[i][0] || dict.ContainsKey(words[i]))
            {
                int num = (i+1) % n;
                if (num == 0) num = n;

                int turn = (int)Math.Ceiling((double)(i + 1) / n);
                if (turn == 0) turn = n;

                return new int[] { num, turn };
            }

            prev = words[i];
            dict.Add(words[i], true);
        }

        return new int[] { 0, 0 };
    }
}