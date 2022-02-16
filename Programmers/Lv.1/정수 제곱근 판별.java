class Solution {
     public long solution(long n) {
        long answer = 0;
     
        if((Math.sqrt(n) == 1 || Math.sqrt(n) % 1 != 0 ) && n != 1)
        	answer = -1;
        else
        	answer = (long)((Math.sqrt(n)+1) * (Math.sqrt(n)+1));
        
        return answer;
	}
}