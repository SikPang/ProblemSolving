class Solution
{
    public int solution(int n, int k)
    {
        int answer = 0;
        string convertedNum = ConvertNumber(n, k);
        string[] arr = convertedNum.Split('0', StringSplitOptions.RemoveEmptyEntries);

        for (int i = 0; i < arr.Length; i++)
        {
            long temp = Convert.ToInt64(arr[i]);

            if (temp <= 1) continue;

            if (CheckPrime(temp)) answer++;
        }

        return answer;
    }

    string ConvertNumber(int n, int k)
    {
        StringBuilder sb = new StringBuilder();

        while (n > 0)
        {
            sb.Insert(0, n % k);
            n /= k;
        }
        
        return sb.ToString();
    }

    bool CheckPrime(long n)
    {
        for (long i = 2; i*i <= n; i++)
            if (n % i == 0) return false;

        return true;
    }
}