class Solution {
    public int solution(int n) {
        int answer = 0;
        boolean isBreak = false;
        
        for(int i=2; i<=n; i++) {
        	isBreak = false;
        	for(int j=2; j*j<=i; j++) {
        		if(i%j==0) 
        		{
        			isBreak = true;
        			break;
        		}
        	}
        	if (isBreak==false) answer++;
        }
        
        return answer;
    }
}