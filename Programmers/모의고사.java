public class Solution {
	public int[] solution(int[] answers) {
		int[][] student = new int[3][answers.length];
		int[] score = new int[3];
		int[] rank = {1, 2, 3};
		
		for (int i = 0; i < answers.length; i++) {	// 1번 학생이 문제를 찍는 방식 넣기
			switch((i+1)%5) {
			case 1:
				student[0][i] = (i + 1) % 5;
				break;
			case 2:
				student[0][i] = (i + 1) % 5;
				break;
			case 3:
				student[0][i] = (i + 1) % 5;
				break;
			case 4:
				student[0][i] = (i + 1) % 5;
				break;
			case 0:
				student[0][i] = 5;
				break;
			}
		}
		
		for (int i = 0; i < answers.length; i++) {	// 2번 학생이 문제를 찍는 방식 넣기
			switch((i+1)%8) {
			case 1:
				student[1][i] = 2;
				break;
			case 2:
				student[1][i] = 1;
				break;
			case 3:
				student[1][i] = 2;
				break;
			case 4:
				student[1][i] = 3;
				break;
			case 5:
				student[1][i] = 2;
				break;
			case 6:
				student[1][i] = 4;
				break;
			case 7:
				student[1][i] = 2;
				break;
			case 0:
				student[1][i] = 5;
				break;
			}
		}
		
		for (int i = 0; i < answers.length; i++) {	// 3번 학생이 문제를 찍는 방식 넣기
			switch((i+1)%10) {
			case 1:
				student[2][i] = 3;
				break;
			case 2:
				student[2][i] = 3;
				break;
			case 3:
				student[2][i] = 1;
				break;
			case 4:
				student[2][i] = 1;
				break;
			case 5:
				student[2][i] = 2;
				break;
			case 6:
				student[2][i] = 2;
				break;
			case 7:
				student[2][i] = 4;
				break;
			case 8:
				student[2][i] = 4;
				break;
			case 9:
				student[2][i] = 5;
				break;
			case 0:
				student[2][i] = 5;
				break;
			}
		}
		
		for (int i = 0; i < answers.length; i++) {
			for (int j = 0; j < 3; j++) {
				if(student[j][i] == answers[i])
					score[j]++;
			}
		}

		for(int j=0; j<2; j++) {
			for(int i=0; i<2; i++) {
				if(score[i]<score[i+1]) {
					int temp = score[i];
					score[i] = score[i+1];
					score[i+1] = temp;
					
					int temp2 = rank[i];
					rank[i] = rank[i+1];
					rank[i+1] = temp2;
				}
			}
		}
		
		if(score[0]!=score[1]) {
			int[] answer = {rank[0]};
			return answer;
		}
		else if(score[0]==score[1] && score[1] != score[2]) {
			int[] answer = {rank[0], rank[1]};
			return answer;
		}
		else {
			int[] answer = {rank[0], rank[1], rank[2]};
			return answer;
		}
	}
}