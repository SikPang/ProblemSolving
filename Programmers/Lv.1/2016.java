public class Solution {
	public String solution(int a, int b) {
		String answer = "";
		int day = 0;

		for (int i = 1; i < a; i++) {
			switch (i) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				day += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				day += 30;
				break;
			case 2:
				day += 29;
				break;
			}
		}
		
		day +=b;
		
		switch((day-1)%7) {
		case 0:
			answer = "FRI";
			break;
		case 1:
			answer = "SAT";
			break;
		case 2:
			answer = "SUN";
			break;
		case 3:
			answer = "MON";
			break;
		case 4:
			answer = "TUE";
			break;
		case 5:
			answer = "WED";
			break;
		case 6:
			answer = "THU";
			break;
		}
		
		return answer;
	}
}