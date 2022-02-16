public class Solution {
	public long solution(long price, long money, long count) {
        long answer = 0;
        
        for(int i=1; i<=count; i++) {
        	answer += (price*i);
        }
        if(money - answer > 0)
        	return 0;
        else
        	answer = (money - answer) * -1;

        return answer;
    }
}
