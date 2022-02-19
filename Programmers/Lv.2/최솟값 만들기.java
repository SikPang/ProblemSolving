import java.util.Arrays;

class Solution {
    public int solution(int[] a, int[] b)
    {
        int answer = 0;

        Arrays.sort(a);
        Arrays.sort(b);
        
        for(int i=0; i<a.length; i++){
            answer += a[i]*b[b.length-1-i];
        }

        return answer;
    }
}