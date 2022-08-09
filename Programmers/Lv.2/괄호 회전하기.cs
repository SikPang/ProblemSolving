using System.Collections.Generic;

class Solution
{
    public int solution(string s)
    {
        int answer = 0;
        List<char> list = new List<char>();

        for (int i = 0; i < s.Length; i++)
            list.Add(s[i]);

        for(int i=0; i<s.Length; i++)
        {
            if (Check(list)) answer++;
            char temp = list[0];
            list.RemoveAt(0);
            list.Add(temp);
        }

        return answer;
    }

    bool Check(List<char> list)
    {
        Stack<char> temp = new Stack<char>();

        foreach(char c in list)
        {
            switch (c)
            {
                case '(':
                case '{':
                case '[':
                    temp.Push(c);
                    break;
                case ')':
                    if(temp.Count==0) return false;
                    if (temp.Peek() == '(') temp.Pop();
                    else return false;
                    break;
                case '}':
                    if (temp.Count == 0) return false;
                    if (temp.Peek() == '{') temp.Pop();
                    else return false;
                    break;
                case ']':
                    if (temp.Count == 0) return false;
                    if (temp.Peek() == '[') temp.Pop();
                    else return false;
                    break;
            }
        }

        if (temp.Count > 0) return false;
        
        return true;
    }
}