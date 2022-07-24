using System.Text;

public class Solution
{
    public int[] solution(string s)
    {
        StringBuilder sb = new StringBuilder(s);
        int[] answer = new int[2];
        int length = 0;

        while (sb.ToString() != "1")
        {
            answer[0]++;

            for (int i = 0; i < sb.Length; i++)
            {
                if (sb[i] == '0')
                {
                    sb.Remove(i, 1);
                    answer[1]++;
                    i--;
                }
            }

            length = sb.Length;
            sb.Clear();

            while (length > 0)
            {
                sb.Insert(0, length % 2);

                length /= 2;
            }
        }
        
        return answer;
    }
}