using System.Collections.Generic;

public class Solution
{
    public int solution(int[] priorities, int location)
    {
        List<int> prio = new List<int>();
        Queue<int> que = new Queue<int>();
        int answer = 0;
        bool isBreaked = false;

        for (int i = 0; i < priorities.Length; i++)
        {
            que.Enqueue(priorities[i]);
            prio.Add(priorities[i]);
        }

        prio.Sort();

        while (true)
        {
            while (true)
            {
                if (prio[prio.Count - 1] == que.Peek())
                {
                    answer++;
                    if (location == 0)
                    {
                        isBreaked = true;
                        break;
                    }

                    prio.RemoveAt(prio.Count - 1);
                    que.Dequeue();
                    location--;
                    break;
                }
                else
                {
                    if (location == 0)
                        location = que.Count - 1;
                    else
                        location--;

                    int temp = que.Peek();
                    que.Dequeue();
                    que.Enqueue(temp);
                }
            }
            if (isBreaked) break;
        }
        return answer;
    }
}