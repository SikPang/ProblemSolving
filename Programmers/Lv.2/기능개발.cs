using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int[] solution(int[] progresses, int[] speeds)
    {
        List<int> progress = new List<int>();
        List<int> speed = new List<int>();
        List<int> result = new List<int>();
        int[] answer = new int[] { };
        int successCnt = 0;

        progress = progresses.ToList();
        speed = speeds.ToList();

        while (progress.Count > 0) {
            successCnt = 0;

            for (int i = 0; i < progress.Count; i++)
            {
                if (progress[i] < 100)
                    progress[i] += speed[i];
            }

            while(progress.Count > 0 && progress[0] >= 100)
            {
                progress.RemoveAt(0);
                speed.RemoveAt(0);

                successCnt++;
            }

            if(successCnt>0)
                result.Add(successCnt);
        }

        answer = result.ToArray();

        return answer;
    }
}