using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int solution(string skill, string[] skill_trees)
    {
        List<char> list = new List<char>();
        bool isBreaked;
        int answer = 0;

        for(int i=0; i<skill.Length; i++)
            list.Add(skill[i]);

        for(int i=0; i<skill_trees.Length; i++)
        {
            List<char> temp = list.ToList();
            isBreaked = false;

            for (int j=0; j<skill_trees[i].Length; j++)
            {
                if (temp.Contains(skill_trees[i][j]))
                {
                    if(temp[0] == skill_trees[i][j])
                        temp.RemoveAt(0);
                    else
                    {
                        isBreaked = true;
                        break;
                    }
                }
            }

            if (!isBreaked) answer++;
        }

        return answer;
    }
}