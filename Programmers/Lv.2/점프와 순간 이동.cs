public class Solution
{
    public int solution(int n)
    {
        int answer = 0;

        while (n > 0)
        {
            if(n%2 == 0)
                n /= 2;
            else
            {
                n = (n - 1) / 2;
                answer++;
            }
        }

        return answer;
    }
}