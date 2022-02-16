class Solution {
    public int solution(int num) {
        int answer = 0;
        long longNum = num;
        
        while(true){
        	if(longNum==1 || answer>=500) break;
        	
            if(longNum%2==0)
                longNum /= 2;
            else
                longNum = longNum * 3 + 1;
            answer++;
        }
        if(answer>=500) answer = -1;
        
        return answer;
    }
}