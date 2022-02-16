public class Solution {
	public int solution(int left, int right) {
        int answer = 0;
        
        for(int i=left; i<=right; i++) {	// 전체 수 반복
        	int cnt = 0;
        	
        	for(int j=1; j<=i; j++) {	    // 해당 수 내에서 반복
        		if(i % j == 0) cnt++;
        	}
        	
        	if(cnt%2 == 0) answer += i;
        	else answer -= i;
        }
        
        return answer;
    }
}