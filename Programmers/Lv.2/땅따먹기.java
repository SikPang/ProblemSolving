class Solution {
    int solution(int[][] land) {
        int answer = 0;
        int max = 0;
        
        for(int i=0; i<land.length; i++){
            for(int j=0; j<land[0].length; j++){
                if(i!=0){
                    max=0;
                    for(int k=0; k<land[0].length; k++){
                        if(k!=j && max<land[i-1][k])
                                max = land[i-1][k];
                    }
                    land[i][j] += max;
                }
                if(answer<land[i][j]) 
                    answer = land[i][j];
            }
        }
        return answer;
    }
}