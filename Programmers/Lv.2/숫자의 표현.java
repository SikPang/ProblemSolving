class Solution {
    public int solution(int n) {
        int answer = 1;
        int number = 0;
        int j=0;
        
        for(int i=n/2+1; i>0; i--){
            j=0;
            number=0;
            while(true){
                if(number>=n || i==j) break;
                number+=(i-j);
                j++;
            }
            if(number==n) answer++;
        }

        return answer;
    }
}