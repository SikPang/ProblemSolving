public class Solution {
	public int[] returnLocation(int n) {
		int x=0;
		int y=0;
		int cnt=1;
		for(int i=0; i<n-1; i++) {
			y++;
			if(cnt%3==0) {
				x++;
				y=0;
			}
			cnt++;
		}
		int[] arr = {x,y};
		return arr;
	}
	
	public String solution(int[] numbers, String hand) {
        String answer = "";
        int locationL = 10;
        int locationR = 12;
        
        for(int i=0; i<numbers.length; i++) {
        	switch(numbers[i]) {
        	case 1:
        	case 4:
        	case 7:
        		answer = answer.concat("L");
        		locationL = numbers[i];
        		break;
        	case 3:
        	case 6:
        	case 9:
        		answer = answer.concat("R");
        		locationR = numbers[i];
        		break;
        	case 2:
        	case 5:
        	case 8:
        	case 0: //numbers[i]를 넣었을 때 왼손과 오른손의 거리를 구하자
        		int[] numberLocation= new int[2];
        		if(numbers[i]!=0)	// 0 일때 따로 처리
        			numberLocation = returnLocation(numbers[i]);
        		else
        			numberLocation = returnLocation(11);
        		int[] leftLocation = returnLocation(locationL);
        		int[] rightLocation = returnLocation(locationR);
        		int distanceL=Math.abs(numberLocation[0]-leftLocation[0])+Math.abs(numberLocation[1]-leftLocation[1]);
        		int distanceR=Math.abs(numberLocation[0]-rightLocation[0])+Math.abs(numberLocation[1]-rightLocation[1]);
        		
        		if(distanceL < distanceR || (distanceL == distanceR && hand.equals("left"))) {
        			answer = answer.concat("L");
        			if(numbers[i]==0)	// 0 일때 따로 처리
        				locationL = 11;
        			else
        				locationL = numbers[i];
        		}
        		else if(distanceL > distanceR || (distanceL == distanceR && hand.equals("right"))){
        			answer = answer.concat("R");
        			if(numbers[i]==0)	// 0 일때 따로 처리
        				locationR = 11;
        			else
            		locationR = numbers[i];
        		}
        		break;
        	}
        }
        return answer;
    }
}