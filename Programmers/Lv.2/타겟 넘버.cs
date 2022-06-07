public class Solution
{
    int[] numbers;
    bool[] isUsed;
    int target;
    int answer = 0;

    public int solution(int[] numbers, int target)
    {
        this.numbers = numbers;
        this.target = target;
        isUsed = new bool[numbers.Length];

        dfs(0);

        return answer;
    }

    void dfs(int depth)
    {
        if (depth == numbers.Length)
        {
            int temp = 0;

            for(int i=0; i<numbers.Length; i++)
            {
                if(isUsed[i] == true)
                    temp += numbers[i];
                else
                    temp -= numbers[i];
            }
            if(temp == target) answer++;

            return;
        }

        for(int i=0; i<2; i++)
        {
            if (i == 0)
                isUsed[depth] = false;
            else
                isUsed[depth] = true;

            dfs(depth + 1);
        }
    }
}