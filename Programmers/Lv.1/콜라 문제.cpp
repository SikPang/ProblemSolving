int solution(int a, int b, int n) {
    int answer = 0;
    int mod = 0;

    do
    {
        while (n >= a)
        {
            mod += n % a;
             n = n / a * b;
             answer += n;
        }
        n += mod;
        mod = 0;
    } while (n >= a);

    return answer;
}